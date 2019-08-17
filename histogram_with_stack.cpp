#include<stdio.h>
#include<stack>
#define MAXN 1005
int n,maxn;
struct node {
	int h,w;
} a[MAXN];
std::stack<node>s;
int min(int x,int y) {
	return x<y?x:y;
}
int max(int x,int y){
	return x>y?x:y;
}
int main() {
	/*
		7
		2 1 3 5 4 3 3 
		freopen("hist.in","r",stdin);
	*/
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i].h);
		a[i].w=1;
	}
	s.push(a[0]);
	for(int i=1; i<n; i++) {
		if(a[i].h>s.top().h) {
			s.push(a[i]);
		}else if(a[i].h==s.top().h){
			node temp;
			temp.h=s.top().h;
			temp.w=s.top().w;
			s.pop();
			temp.w+=a[i].w;
			s.push(temp);
		} else {			
			while(s.top().h>a[i].h){			
				node temp;
				temp.h=s.top().h;
				temp.w=s.top().w;
				s.pop();
				maxn=max(maxn,temp.h*temp.w);
				if(!s.empty()){
					node temp1;
					temp1.h=s.top().h;
					temp1.w=s.top().w;
					if(temp1.h<a[i].h){
						temp.h=a[i].h;
						temp.w+=a[i].w;
						s.push(temp);
					}else if(temp1.h==a[i].h){
						s.pop();
						temp.h=a[i].h;
						temp.w+=a[i].w;
						temp.w+=temp1.w;
						s.push(temp);
					}else{
						s.pop();
						temp.h=temp1.h;					
						temp.w+=temp1.w;
						s.push(temp);
					}												
				}else{
					temp.h=a[i].h;
					temp.w+=a[i].w;
					s.push(temp);				
				}
			}	
		}
		std::stack<node> s_tmp;
		while(!s.empty()){
			s_tmp.push(s.top());
			s.pop();
		}
		printf("###################%d[%d]####################\n",i,maxn);
		while(!s_tmp.empty()){
			s.push(s_tmp.top());
			printf("[%d,%d]\n",s_tmp.top().h,s_tmp.top().w);
			s_tmp.pop();
		}
	}
		printf("####%d####\n",__LINE__);
		while(!s.empty()){
			node temp;
			temp.h=s.top().h;
			temp.w=s.top().w;
			maxn=max(maxn,temp.h*temp.w);
			s.pop();
			printf("####%d####\n",__LINE__);
			if(!s.empty()){
				node temp1;
				temp1.h=s.top().h;
				temp1.w=s.top().w;
				temp1.w+=temp.w;
				s.pop();
				s.push(temp1);
			}			
		}
		printf("ans=%d\n",maxn);
}
