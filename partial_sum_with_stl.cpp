#include<stdio.h>
#include<numeric>
#define MAXN 15
using namespace std;
int a[MAXN],result[MAXN],n,ans;
int main() {
	freopen("data.in","r",stdin);
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=0; i<n; i++) {
		partial_sum(a+i,a+n,result);
		for(int j=0; j<n-i; j++) {
			printf("%d ",result[j]);
		}
		printf("\n");
	}
	return 0;
}
