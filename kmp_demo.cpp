#include <iostream>
using namespace std;
char main_str[1000] = "ABAAABBABBAAAABABAAABAAA";
char s[1000] = "ABABAAAB";
int s_next[1000] = { 0 };
void builds_next() {
	for (int i = 1,j=0; i < strlen(s); i++) {
		//每次进来，j表示s_next[i-1]的数值
		//即代表前i-1字符的最长公共前后缀长度为j
		//同时表示从S[j]开始是不等的
		//同时表示S[j]是前i字符前缀目前新填的字符
		//前缀填的是S[j]，后缀新填的字符是S[i]
		while (j>0&&s[j] != s[i]) {
			//通过j的变化，把前缀拉到后缀的位置
			//while想象多次前缀拉到后缀的位置
			j = s_next[j - 1];
		}
		if (s[j] == s[i])
			j++;
		s_next[i] = j;
	}
}
void dump_next() {
	cout << "     ";
	for (int i = 0; i < strlen(s); i++) {
		cout << i << " ";
	}
	cout << endl;
	cout << "     ";
	for (int i = 0; i < strlen(s); i++) {
		cout << s[i] << " ";
	}
	cout << endl;
	cout << "Next:";
	for (int i = 0; i < strlen(s); i++) {
		cout << s_next[i] << " ";
	}
	cout << endl;
}
//主串的指针位置始终不后退
//模式串根据情况来回移动
int kmp_find() {
	int j = 0;
	for (int i = 0; i < strlen(main_str); i++) {
		//i永远不后退
		while (j>0&&main_str[i] != s[j]) {
			j = s_next[j - 1];//通过j的变化，把前缀拉到后缀的位置
		}
		if (main_str[i] == s[j]) {
			j++;
		}
		if (j == strlen(s)) {
			cout << "FOUND! start at "<<i+1-strlen(s) << endl;
			return 1;
			break;
		}
	}
	return 0;
}
int main() {
	builds_next();
	dump_next();
	kmp_find();
	return 0;
}
