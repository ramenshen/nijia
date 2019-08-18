#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct House {
	int distance;
	int score;
};
//#define max(A,B) (A)>(B)?(A):(B)
House house[500000+100];
int opt[500000+100];
int jump;
int totalscore;
int len;
int ans=-1;
int lstep;
int rstep;
int isOk(int m) {
	//printf("m=%d\n",m);
	lstep = ((jump-m)<=0)?1:(jump-m);
	rstep = jump+m;
	//printf("lstep=%d rstep=%d\n",lstep,rstep);
	queue<int> q;
	q.push(0);
	for(int i=0; i<len; i++) {
		opt[i]=INT_MIN;
	}
	opt[0]=0;
	while(!q.empty()) {
		int start = q.front();
#if 1
		for(int end=start+1; end<len; end++) {
			int gap=house[end].distance-house[start].distance;
			if(gap<lstep) {
				continue;
			} else if(gap>=lstep&&gap<=rstep) {
				if(opt[end]==INT_MIN) {
					q.push(end);
				}
				opt[end]=max(opt[end],opt[start]+house[end].score);
				if(opt[end]>=totalscore) {
					return 1;
				}
			} else {
				break;
			}
		}
#else
		for(int step=lstep; step<=rstep; step++) {
			int newd=(house[start].distance+step);
			for(int end=start+1; end<len; end++) {
				if(newd==house[end].distance) {
					//cout<<"prepare push "<<end<<endl;
					if(opt[end]==INT_MIN) {
						//cout<<"push "<<end<<endl;
						q.push(end);
					}
					opt[end]=max(opt[end],opt[start]+house[end].score);
					//cout<<"opt["<<end<<"] "<<opt[end]<<endl;
					if(opt[end]>=totalscore) {
						return 1;
					}
					break;
				} else if(newd<house[end].distance) {
					break;
				} else {
					continue;
				}

			}
		}
#endif
		q.pop();
	}
	return 0;
}
int calc(int m) {
	//printf("m=%d\n",m);
	lstep = ((jump-m)<=0)?1:(jump-m);
	rstep = jump+m;
	
	for(int i=0; i<len; i++) {
		opt[i]=INT_MIN/2;
	}
	opt[0]=0;
	for(int i=1; i<len; i++) {
		int max_house=INT_MIN/2;
		//for(int j=0; j<i; j++) 
		for(int j=i-1; j>=0; j--) 
		{
			int tmp=house[i].distance-house[j].distance;
			if(tmp>=lstep&&tmp<=rstep) {
				max_house=max(max_house,opt[j]);
			}
		}
		opt[i]=max_house+house[i].score;
		if(opt[i]>=totalscore){
			return 1;
		}
	}
	return 0;
}
int main() {
	freopen("p3957_data.in","r",stdin);
	scanf("%d %d %d",&len,&jump,&totalscore);
	for(int i=1; i<len+1; i++) {
		scanf("%d %d",&house[i].distance,&house[i].score);
	}
	int l=0;
	int r=house[len].distance-jump;
	//memset(opt,-128,sizeof(opt));
	len = len+1;
	int m=(l+r)/2;
	while(l<=r) {
		if(calc(m)) {
			//cout<<m<<" is ok"<<endl;
			ans=m;
			r=m-1;
		} else {
			l=m+1;
		}
		m=(l+r)/2;
	}
	printf("%d\n",ans);
	return 0;
}
