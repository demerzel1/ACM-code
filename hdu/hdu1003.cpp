#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int dp[maxn];
int a[maxn];
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        if(cas>1)
            printf("\n");
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        dp[0]=a[0];
        int ans=dp[0];
        int ind=0;
        int l=0;
        int temp=0;
        for(int i=1;i<n;i++){
            if(dp[i-1]<0){
                dp[i]=a[i];
                temp=i;
            }else
                dp[i]=dp[i-1]+a[i];
            if(dp[i]>ans){
                ans=dp[i];
                ind=i;
                l=temp;
            }
        }
        int tind=ind;
        for(tind=ind;tind>=0;tind--){
            if(dp[tind]<0){
                break;
            }
        }
        tind++;
        printf("Case %d:\n%d %d %d\n",cas,ans,l+1,ind+1);
    }
    return 0;
}
