#include<stdio.h>
#include<string.h>
#define MAXN 105
int opt[MAXN][MAXN];
char a[MAXN], b[MAXN];
struct point {
	int x;
	int y;
};
point path[MAXN][MAXN];
int max(int x, int y) {
	return x > y ? x : y;
}
int main() {
	freopen("lca.in", "r", stdin);
	scanf("%s%s", &a, &b);
	printf("a=%s b=%s\n", a, b);
	for (int i = 0; i < strlen(a); i++) {
		for (int j = 0; j < strlen(b); j++) {
			if (a[i] == b[j]) {
				opt[i + 1][j + 1] = opt[i][j] + 1;
				path[i + 1][j + 1].x = i;
				path[i + 1][j + 1].y = j;
			}
			else if (a[i] != b[j]) {
				opt[i + 1][j + 1] = max(opt[i + 1][j], opt[i][j + 1]);
				if (opt[i + 1][j + 1] == opt[i + 1][j]) {
					path[i + 1][j + 1].x = i + 1;
					path[i + 1][j + 1].y = j;
				}
				else {
					path[i + 1][j + 1].x = i;
					path[i + 1][j + 1].y = j + 1;
				}
			}
		}
	}
	printf("\n\n\n");
	printf("      ");
	for (int j = 0; j <= strlen(b); j++) {
		printf("%c  ", b[j]);
	}
	printf("\n\n");

	for (int i = 0; i <= strlen(a); i++) {
		if (i)
			printf("%c  ", a[i - 1]);
		else
			printf("   ");
		for (int j = 0; j <= strlen(b); j++) {
			printf("%d  ", opt[i][j]);
		}
		printf("\n\n");
	}
	printf("\n\n\n");
	printf("%d\n", opt[strlen(a)][strlen(b)]);
	int opt_value = opt[strlen(a)][strlen(b)];
	printf("(%d,%d)[%d] \n", strlen(a), strlen(b), opt[strlen(a)][strlen(b)]);
	int parent_x = path[strlen(a)][strlen(b)].x;
	int parent_y = path[strlen(a)][strlen(b)].y;
	int old_parent_x = parent_x;
	//int old_parent_y = parent_y;
	while (parent_x >= 1 && parent_y >= 1) {

		printf("(%d,%d)[%d]\n", parent_x, parent_y, opt[parent_x][parent_y]);
		old_parent_x = parent_x;
		//	old_parent_y = parent_y;
		parent_x = path[old_parent_x][parent_y].x;
		parent_y = path[old_parent_x][parent_y].y;
		if (opt_value != opt[parent_x][parent_y]) {
			printf("%c[%d]\n", a[old_parent_x - 1], old_parent_x);
		}
		opt_value = opt[parent_x][parent_y];
	}

	return 0;
}