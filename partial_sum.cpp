#include<stdio.h>
#define MAXN 15
int a[MAXN],n,ans;
int main(){
    freopen("data.in","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int length=1;length<=n;length++){
        for(int start=0;(start+length)<=n;start++){
            for(int i=start;i<start+length;i++){
                ans+=a[i];
            }
            printf("%d ",ans);
            ans=0;
        }
        printf("\n");
    }
    return 0;
}
