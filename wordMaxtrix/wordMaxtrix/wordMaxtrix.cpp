// wordMaxtrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stdio.h>
#define MAXN 15
char map[MAXN][MAXN], find[MAXN] = "yizhong";
int check[MAXN][MAXN], n;
const int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
//const int dir[1][2] = { {0,1} };

#if 1
bool isOK(int col, int row) {
	if (col < 0|| row < 0||col>=n||row>=n)
		return false;
	return true;
}
void search_direction_dfs(int level,int direction,int col,int row) {
	if (map[col][row] != find[level])
		return;
	if (level == (strlen(find)-1)) {
		for (int i = 0; i <= level; i++) {
			check[col][row] = 1;
			col -= dir[direction][0];
			row -= dir[direction][1];
		}
		return;
	}else {
		int new_col = col + dir[direction][0];
		int new_row = row + dir[direction][1];
		if (!isOK(new_col, new_row)) {
			return;
		}
		search_direction_dfs(level + 1, direction, new_col, new_row);
	}
}
void search_dfs(int level, int col, int row) {
	//搜索8个方向
	for (int direction = 0; direction < 8; direction++) {
		int new_col = col + dir[direction][0];
		int new_row = row + dir[direction][1];
		if (isOK(new_col, new_row))//判断坐标合法性
		{
			search_direction_dfs(level+1, direction,new_col,new_row);
		}
	}
	
}
#else
void search(int level, int col, int row) {
	//direct 1
	for (int direction = 0; direction < 8; direction++) {
			int i = 0;
			for (i = 1; i < strlen(find); i++) {
				if ((col + i * dir[direction][0]) < 0 || (row + i * dir[direction][1] <0)) {
					break;
				}
				if ((col + i * dir[direction][0]) >= n || (row + i * dir[direction][1] >= n) ) {
					break;
				}
				if (map[col+i*dir[direction][0]][row + i*dir[direction][1]] != find[level + i]) {
					break;
				}
			}
			if (i == strlen(find)) {
				check[col][row] = 1;
				for (int i = 1; i < strlen(find); i++) {
					check[col + i * dir[direction][0]][row + i * dir[direction][1]] = 1;
				}
			}	
	}
}
#endif
int main() {
	int max_house = -2147483648;
	freopen("data.in","r",stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char tmp;
		scanf("%c", &tmp);//故意取走换行符
		for (int j = 0; j < n; j++) {
			scanf("%c", &map[i][j]);
		}		
	}
	int pos;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'y')
#if 1
				search_dfs(0,i,j);
#else
				search(0, i, j);
#endif
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j]) {
				printf("%c", map[i][j]);
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
}