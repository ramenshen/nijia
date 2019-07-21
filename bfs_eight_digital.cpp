// eight_digital.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include <iomanip>
#include <algorithm>
using namespace std;
#define N 362885
int state[N][9], goal[9];
int now_distance[N];
//int fact[9];
int move_xy[4][2] = { 
	{0,-1},
	{-1,0},
	{0,1},
	{1,0}
};
set<int>vis;

bool isOK(int zero_x, int zero_y)///判断坐标（zero_x,zero_y）是否合法
{
	if (zero_x >= 0 && zero_x < 3 && zero_y >= 0 && zero_y < 3)
		return true;
	return false;
}

void init()
{
	vis.clear();
}
int InsertIfNotExist(int s)
{
	int v = 0;
	for (int i = 0; i < 9; i++)
		v = v * 10 + state[s][i];///将当前状态转化为9位数
	if (vis.count(v))
		return 0;///集合中已经存在
	vis.insert(v);///加入集合
	return 1;
}
void print(int &a) {
	cout << setw(2) << a;
}
int bfs()
{
	int front = 1, back = 2, zero;
	init();
	while (front < back)///队列非空
	{
		int (&s)[9] = state[front];///取队头元素		
		if (!memcmp(s, goal, sizeof(s)))///到达目标状态
			return front;
		for (zero = 0; zero < 9; zero++) {
			if (!s[zero]) break;///找0所在的位置
		}
		int zero_x = zero / 3;
		int zero_y = zero % 3;//(zero_x,zero_y)为0的坐标
		cout << "Prepare to Insert " << now_distance[front] + 1 << " Layer" << endl;
		for (int i = 0; i < 4; i++)//4个方向
		{
			int new_x = zero_x + move_xy[i][0];
			int new_y = zero_y + move_xy[i][1];
			int new_zero = new_x * 3 + new_y;//(new_x,new_y)是新的坐标，new_zero是新的位置
			if (isOK(new_x, new_y))
			{
				int (&t)[9] = state[back];
				memcpy(&t, &s, sizeof(s));///扩展新结点
				t[new_zero] = s[zero];///这两行实现0的位置的移动
				t[zero] = s[new_zero];///
				now_distance[back] = now_distance[front] + 1;///更新新节点的距离值				
				if (InsertIfNotExist(back)) {///如果成功插入，队列元素+1--很重要，判断节点是否存在过
#if 1
					cout << "state[" << back << "]:";
					for_each(&state[back][0], &state[back][9], print);
					cout << endl;
					if (!memcmp(t, goal, sizeof(t)))///到达目标状态
						return back;
#endif
					back++;
				}
			}
		}
		front++;///修改对头指针（即删除对头元素）
	}
	return 0;
}
int main()
{
	/*
	data.in content:
	2 8 3 1 6 4 7 0 5
	1 2 3 7 8 4 0 6 5
	*/
	freopen("data.in","r",stdin);
	for (int i = 0; i < 9; i++)
		scanf("%d", &state[1][i]);///起始状态
	for (int i = 0; i < 9; i++)
		scanf("%d", &goal[i]);///目标状态
	int ans = bfs();///返回目标状态的下标
	if (ans) 
		printf("%d\n", now_distance[ans]);
	else
		printf("Impossible\n");
	return 0;
}
