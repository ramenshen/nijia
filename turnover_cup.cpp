#include <iostream>
struct node {
	int x;
	int y;
};
struct node_array {
	int level;
	int father;
	int mother;
	struct node* n;
};
using namespace std;
int g_current_level=0;
int g_node_num = 0;
struct node_array level_node_array[1000];
void print_level_node_array(int once, int total);
void print_found_path(int level_node_index,int node_index,int total, int once) {
	int i = 0;
	if (level_node_index == -1)
		return;
	//for (i = 0; i < once + 1; i++) {
	//	if ((level_node_array[level_node_index].n[i].x + level_node_array[level_node_index].n[i].y) == total)
			cout << "(" << level_node_array[level_node_index].n[node_index].x << "," << level_node_array[level_node_index].n[node_index].y << ")" << " ";

	//}
	if (level_node_array[level_node_index].father != -1)
		cout << "<-----";
	else
		cout << endl;
	print_found_path(level_node_array[level_node_index].father, level_node_array[level_node_index].mother,total,once);
}
void start_turnover_cups(int level,int total,int once) {
	int i = 0;
	int level_node_array_index = 0;
	//g_current_level++;

	print_level_node_array(total,once);
	cout << "Try to find the node in level " << level << endl;
	while(level_node_array_index < sizeof(level_node_array) / sizeof(struct node_array)) {
		if (level_node_array[level_node_array_index].level != level) {
			level_node_array_index++;
			continue;
		}
		int node_array_index = 0;
		for (node_array_index = 0; node_array_index <= once; node_array_index++) {
			if ((level_node_array[level_node_array_index].n[node_array_index].x + level_node_array[level_node_array_index].n[node_array_index].y) != total)
				continue;
			cout << "process level node array " << level_node_array_index << endl;
			cout << "process node ( " << level_node_array[level_node_array_index].n[node_array_index].x <<","<< level_node_array[level_node_array_index].n[node_array_index].y<<")"<< endl;
			int malloc_flag = 0;
			for (i = 1; (i <= level_node_array[level_node_array_index].n[node_array_index].x) && (i <= once); i++) {
				if ((level_node_array[level_node_array_index].n[node_array_index].y < (once - i)))
					continue;
				if (!malloc_flag) {
					g_node_num++;
					level_node_array[g_node_num].level = level + 1;
					level_node_array[g_node_num].father = level_node_array_index;
  					level_node_array[g_node_num].mother = node_array_index;
					level_node_array[g_node_num].n = new node[once + 1];
					memset(level_node_array[g_node_num].n, 0, sizeof(node)*(once + 1));
					malloc_flag = 1;
				}
				level_node_array[g_node_num].n[i].x = level_node_array[level_node_array_index].n[node_array_index].x+ (once - 2 * i);
				level_node_array[g_node_num].n[i].y = level_node_array[level_node_array_index].n[node_array_index].y+ (2 * i - once);
				if (level_node_array[g_node_num].n[i].x == 0) {
					cout << "found!!!!" << endl;
					print_level_node_array(total, once);
					print_found_path(g_node_num,i,total,once);					
					return;
				}
			}
		}
		level_node_array_index++;
	}
	start_turnover_cups(level+1,total,once);
}
void init_turnover_cups(int total,int once) {
	level_node_array[g_node_num].level = g_current_level;
	level_node_array[g_node_num].n = new node[once+1];
	memset(level_node_array[g_node_num].n,0,sizeof(node)*(once+1));
	level_node_array[g_node_num].n->x = total;
	level_node_array[g_node_num].n->y = 0;
	
	start_turnover_cups(0,total,once);
	//g_current_level++;
}
void print_level_node_array(int total,int once) {
	int level_node_array_index = 0;
//	cout << __FUNCTION__ << __LINE__ << endl;
	while (level_node_array_index < sizeof(level_node_array) / sizeof(struct node_array)) {
		if (level_node_array[level_node_array_index].level== -1)
			break;
		cout << "Level " << level_node_array[level_node_array_index].level << ":";
		cout << "Father " << level_node_array[level_node_array_index].father<< ":";
		cout << "Mother " << level_node_array[level_node_array_index].mother << ":";
		int i = 0;
		for (i = 0; i < once + 1; i++) {
			if ((level_node_array[level_node_array_index].n[i].x + level_node_array[level_node_array_index].n[i].y) == total)
				cout << "(" << level_node_array[level_node_array_index].n[i].x << "," << level_node_array[level_node_array_index].n[i].y << ")" << " ";
				
		}
		cout << endl;
		
		level_node_array_index++;
	}
//	cout << __FUNCTION__ << __LINE__ << endl;
}
void init_level_node_array() {
	int level_node_array_index = 0;
	//memset(level_node_array, 0, sizeof(level_node_array));
	while (level_node_array_index < sizeof(level_node_array) / sizeof(struct node_array)) {
		level_node_array[level_node_array_index].level = -1;
		level_node_array[level_node_array_index].father = -1;
		level_node_array[level_node_array_index].mother = -1;
		level_node_array[level_node_array_index].n = NULL;
		level_node_array_index++;
	}
}
int main() {
	cout << "initial 1000 node arraies" << endl;	
	int cups_total_num = 0;
	int cups_tureover_num_once = 0;
	init_level_node_array();
	cout << "please input the total number of cups:";
	cin >> cups_total_num;
	cout << "Pleae input the number of turn over once time:";
	cin >> cups_tureover_num_once;
	init_turnover_cups(cups_total_num, cups_tureover_num_once);
	 system("pause");
}