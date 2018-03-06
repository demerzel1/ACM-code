#include<bits/stdc++.h>
using namespace std;
#define maxn 100005

int a[maxn];
int dp[maxn];
int dp1[maxn];
int dp2[maxn];
int n;

int main() {
    while(~scanf("%d",&n)) {
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        fill(dp,dp+n,INT_MAX);
        memset(dp1,0,sizeof(dp1));
        for(int i=0; i<n; i++) {
            *lower_bound(dp,dp+n,a[i])=a[i];
            dp1[i]=lower_bound(dp,dp+n,INT_MAX)-dp-1;
            //   cout<<dp1[i]<<"\n";
        }
        fill(dp,dp+n,INT_MAX);
        memset(dp2,0,sizeof(dp2));
        for(int i=n-1; i>=0; i--) {
            *lower_bound(dp,dp+n,a[i])=a[i];
            dp2[i]=lower_bound(dp,dp+n,INT_MAX)-dp-1;
            //    cout<<dp2[i]<<"\n";
        }
        int ans=1;
        for(int i=1; i<n; i++) {
            if(dp1[i]==dp1[i-1]+1)
                ans=max(ans,(min(dp1[i],dp2[i]))*2+1);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
