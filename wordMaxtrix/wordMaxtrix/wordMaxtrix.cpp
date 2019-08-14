// wordMaxtrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stdio.h>
#define MAXN 15
char map[MAXN][MAXN], find[MAXN] = "yizhong";
int check[MAXN][MAXN], n;
const int dir[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
//void search(int t,int col,int row){
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			if(map[i][j]==find[t]){
//				for(int k=0;k<8;j++){
//					if(col+dir)
//				} 
//				check[i][j]=1;
//			}
//		}
//	}
//}
void search(int level, int col, int row) {
	//direct 1
	for (int times = 0; times < 8; times++) {
			int i = 0;
			for (i = 1; i < strlen(find); i++) {
				if ((col + i * dir[times][0]) < 0 || (row + i * dir[times][1] <0)) {
					break;
				}
				if ((col + i * dir[times][0]) >= n || (row + i * dir[times][1] >= n) ) {
					break;
				}
				if (map[col+i*dir[times][0]][row + i*dir[times][1]] != find[level + i]) {
					break;
				}
			}
			if (i == strlen(find)) {
				check[col][row] = 1;
				for (int i = 1; i < strlen(find); i++) {
					check[col + i * dir[times][0]][row + i * dir[times][1]] = 1;
				}
			}	
	}
}
int main() {
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
			if(map[i][j]=='y')
				search(0, i, j);
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