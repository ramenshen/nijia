// prim_demo_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <iterator>
using namespace std;
#define MAXN 1005
int MAX = 0x7fffffff;
int nd[5][5] = {
	{0,3,1,MAX,MAX},
	{3,0,MAX,4,6},
	{1,MAX,0,2,7},
	{MAX,4,2,0,5},
	{MAX,6,7,5,0},
};
int vis[MAXN] = { 0 };
int dis[MAXN] = { 0 };
int nodeNum = 5;
int main() {
	int order = 1;
	int ans = 0;
   //init dis
	for (int i = 0; i < nodeNum; i++) {
		dis[i] = nd[0][i];
	}
	for (int i = 0; i < nodeNum; i++) {	
		int min = MAXN;
		int pos = -1;
		int min_idx = -1;
		//find the shortest distance
		for (int j = 0; j < nodeNum; j++) {
			if (!vis[j] && min > dis[j]) {
				min = dis[j];
				min_idx = j;
			}
		}
		//把最小距离加入vis
		vis[min_idx] = order;
		order++;
		ans += min;
		//更新distance
		for (int unvisit_j = 0; unvisit_j < nodeNum; unvisit_j++) {

			if (!vis[unvisit_j]) {

				for (int visit_i = 0; visit_i < nodeNum; visit_i++) {

					if (vis[visit_i]&& visit_i != unvisit_j) {

						if (nd[visit_i][unvisit_j] < dis[unvisit_j]) {

							dis[unvisit_j] = nd[visit_i][unvisit_j];
						
						}
					}
				}
			}
		}
	}
	copy(vis, vis + nodeNum, ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "ans=" << ans << endl;
	int O[MAXN] = { 0 };
	int want_find_order = 1;
	for (int i = 0; i < nodeNum; i++) {
		for (int j = 0; j < nodeNum; j++) {
			if (vis[j] == want_find_order)
				O[i] = j;
		}
		want_find_order++;
	}
	ans = 0;
	for (int i = 1; i < (nodeNum ); i++) {
		int min = MAXN;
		for (int j = 0; j < i; j++) {
			if (min > nd[O[j]][O[i]]) {
				min = nd[O[j]][O[i]];
			}
		}
		ans += min;
	}
	cout << "ans=" << ans << endl;
}

