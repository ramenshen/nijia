// maza_dfs.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stack>
using namespace std;

struct Point {
	//行与列
	int row;
	int col;
	Point() {
		this->row = 0;
		this->col = 0;
	}
	Point(const Point& p) {
		this->row = p.row;
		this->col = p.col;
	}
	Point(int x, int y) {
		this->row = x;
		this->col = y;
	}

	bool operator!=(const Point& rhs) {
		if (this->row != rhs.row || this->col != rhs.col)
			return true;
		return false;
	}	
};
int direction[4][2] = {
	{-1,0},
	{0,1},
	{1,0},
	{0,-1}
};
int isOk(const Point& p, int m, int n) {
	if (p.row >= 0 && p.row < m&&p.col >= 0 && p.col < n)
		return 1;
	return 0;
}
//func:获取相邻未被访问的节点
//para:mark:结点标记，point：结点，m：行，n：列
//ret:邻接未被访问的结点
Point getAdjacentNotVisitedNode(bool** mark, Point point, int m, int n) {
	Point resP(-1, -1);
	if (point.row - 1 >= 0 && mark[point.row - 1][point.col] == false) {//上节点满足条件
		resP.row = point.row - 1;
		resP.col = point.col;
		return resP;
	}
	if (point.col + 1 < n&&mark[point.row][point.col + 1] == false) {//右节点满足条件
		resP.row = point.row;
		resP.col = point.col + 1;
		return resP;
	}
	if (point.row + 1 < m&&mark[point.row + 1][point.col] == false) {//下节点满足条件
		resP.row = point.row + 1;
		resP.col = point.col;
		return resP;
	}
	if (point.col - 1 >= 0 && mark[point.row][point.col - 1] == false) {//左节点满足条件
		resP.row = point.row;
		resP.col = point.col - 1;
		return resP;
	}
	return resP;
}

int func(int n) {
	n += 1;
	return n;
}

//func：给定二维迷宫，求可行路径
//para:maze：迷宫；m：行；n：列；startP：开始结点 endP：结束结点； pointStack：栈，存放路径结点
//ret:无
void mazePath(void* maze, int m, int n, const Point& startP, Point endP, stack<Point>& pointStack) {
	//将给定的任意列数的二维数组还原为指针数组，以支持下标操作
	int** maze2d = new int*[m];
	for (int i = 0; i < m; ++i) {
		maze2d[i] = (int*)maze + i * n;
	}

	if (maze2d[startP.row][startP.col] == 1 || maze2d[endP.row][endP.col] == 1)
		return;                    //输入错误

	//建立各个节点访问标记
	bool** mark = new bool*[m];
	for (int i = 0; i < m; ++i) {
		mark[i] = new bool[n];
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			mark[i][j] = *((int*)maze + i * n + j);
		}
	}

	//将起点入栈
	pointStack.push(startP);
	mark[startP.row][startP.col] = true;

	//栈不空并且栈顶元素不为结束节点
	while (pointStack.empty() == false && pointStack.top() != endP) {
#if 1
		Point p = pointStack.top();
		int i = 0;
		for (i = 0; i < 4; i++) {
			Point newP;
			newP.row = p.row + direction[i][0];
			newP.col = p.col + direction[i][1];
			if (isOk(newP, m, n)&&mark[newP.row][newP.col] == false) {
				mark[newP.row][newP.col] = true;
				pointStack.push(newP);
				break;
			}
		}
		if (i==4) {
			pointStack.pop();
		}
#else
		Point adjacentNotVisitedNode = getAdjacentNotVisitedNode(mark, pointStack.top(), m, n);
		if (adjacentNotVisitedNode.row == -1) { //没有未被访问的相邻节点
			pointStack.pop(); //回溯到上一个节点
			continue;
		}

		//入栈并设置访问标志为true
		mark[adjacentNotVisitedNode.row][adjacentNotVisitedNode.col] = true;
		pointStack.push(adjacentNotVisitedNode);
#endif
	}
}

int main() {
	int maze[5][5] = {
		{0,0,0,0,1},
		{0,1,0,1,0},
		{0,0,1,0,0},
		{1,0,1,0,1},
		{0,0,0,0,0}
	};
	int n = 3;
	n=func(n);
	cout << "n=" << n << endl;
	Point startP(0, 0);
	Point endP(4, 4);
	stack<Point>  pointStack;
	mazePath(maze, 5, 5, startP, endP, pointStack);

	//没有找打可行解
	if (pointStack.empty() == true)
		cout << "no right path" << endl;
	else {
		stack<Point> tmpStack;
		cout << "path:";
		while (pointStack.empty() == false) {
			tmpStack.push(pointStack.top());
			pointStack.pop();
		}
		while (tmpStack.empty() == false) {
			printf("(%d,%d) ", tmpStack.top().row, tmpStack.top().col);
			tmpStack.pop();
		}
	}
	getchar();
}