#include<iostream>
#include<iterator>
using namespace std;
int a[10] = { 123,1547,13,66,1436,137,4363,1,55,2356 };
int main() {
	for (int end = 0; end < 10; end++) {
		int min=0x7fffffff;      
		int min_pos = -1;
		for (int i = end; i < 10; i++) {
			if (a[i] < min) {
				min = a[i];
				min_pos = i;
			}
		}
		swap(a[end], a[min_pos]);
	}
	copy(a, a + 10, ostream_iterator<int>(cout, " "));
	return 0;
}