#include<stdio.h>
#include<stack>
#define MAXN 1005
int n,maxn;
int min(int x,int y) {
	return x<y?x:y;
}
int max(int x,int y){
	return x>y?x:y;
}
class node {
public:
	int h;
	int w;
	bool operator>(const node& x){
		return this->h>x.h; 
	} 
	bool operator<(const node& x){
		return this->h<x.h; 
	} 
	bool operator==(const node& x){
		return this->h==x.h; 
	} 
	node* operator=(const node& x){
		this->h = x.h;
		this->w = x.w;	
		return this;
	}
	node* operator+(const node& x){
		this->h = min(this->h,x.h);
		this->w+=x.w;	
		return this;
	}
	node& operator+=(const node& x){
		this->h = min(this->h,x.h);
		this->w+=x.w;	
		return *this;
	}
} a[MAXN];
std::stack<node>s;

int main() {
	freopen("hist.in","r",stdin);
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i].h);
		a[i].w=1;
	}	
	s.push(a[0]);
	for(int i=1; i<n; i++) {
		if(a[i]>s.top()) {
			s.push(a[i]);
		}else if(a[i]==s.top()){
			s.top()+=a[i];		
		} else {			
			while(s.top().h>a[i].h){			
				node temp=s.top();				
				s.pop();
				maxn=max(maxn,temp.h*temp.w);
				if(!s.empty()){
					node temp1=s.top();
					if(temp1<a[i]){						
						temp+=a[i];
						s.push(temp+=a[i]);					
					}else if(temp1==a[i]){
						s.pop();					
						temp+=a[i];
						temp+=temp1;
						s.push(temp);
					}else{
						s.pop();										
						temp+=temp1;
						s.push(temp);
					}												
				}else{
					temp+=a[i];
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
			node temp=s.top();
			maxn=max(maxn,temp.h*temp.w);
			s.pop();
			printf("####%d####\n",__LINE__);
			if(!s.empty()){
				node temp1=s.top();			
				temp1+=temp;
				s.pop();
				s.push(temp1);
			}			
		}
		printf("ans=%d\n",maxn);
}
