#include<iostream>
#include<queue>
#include<algorithm>
#include<stdio.h>
#include<limits.h>
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
deque<int> q;
int calc(int m) {
	//printf("m=%d\n",m);
	lstep = ((jump-m)<=0)?1:(jump-m);
	rstep = jump+m;

	for(int i=0; i<len; i++) {
		opt[i]=INT_MIN/2;
	}
	opt[0]=0;
#if 1
	q.clear();
#endif
	int cur=0;//第1个判断是否应该可达i
	for(int i=1; i<len; i++) {
		//需要剔除一些退役
		while(!q.empty()&&((house[i].distance-house[q.front()].distance)>rstep))
			q.pop_front();
		//想把可达的点加进来加到dq
		while(cur<i) {
			if((house[cur].distance+lstep)>house[i].distance) {
				break;//说明离目标点i太近，那越往后面只能越不可达 ，只会越来越近
			} else if((house[cur].distance+rstep)<house[i].distance) {
				cur++;
				continue;//说明离目标点i太远，那需要到后面去找
			} else {
				//说明当前可达i点 ，应该加入dq，
				//add to dequeue
				while(!q.empty()&&opt[q.back()]<=opt[cur])
					q.pop_back();
				q.push_back(cur);
				cur++;
			}
		}
		//通过上面的运算，保证dq一定可达i，但是dq可能为空，
		if(q.empty())
			opt[i]=INT_MIN/2;
		else {
			opt[i]=opt[q.front()]+house[i].score;
		}
		if(opt[i]>=totalscore) {
			//cout<<"opt["<<i<<"]"<<opt[i]<<" totalscore="<<totalscore<<endl;
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
