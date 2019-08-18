#include<stdio.h>
#include<deque>
std::deque<int>q;
int a[1005]= {500,460,428,510,473,485,485,502,485,450};
int length=10,range=3;
int main() {
	q.push_back(0);
	for(int i=1; i<length; i++) {
		printf("i=%d ",i);
		if(i-q.front()>=range) {
			q.pop_front();
		}
		while(!q.empty()&&a[q.back()]<=a[i]) {
			q.pop_back();
		}
		q.push_back(i);
		for(int j=0; j<q.size(); j++) {
			printf("%d ",a[q[j]]);
		}
		printf("\n");
	}
	return 0;
}
