#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define maxn 1005
int n,m;
ll num[maxn];
ll dp[maxn][maxn];
int main(){
    while(cin>>n>>m&&(n&&m)){
        for(int i=1;i<=n;i++)
            cin>>num[i];
        for(int k=0;k<=n;k++){
            dp[0][k]=0;
            for(int i=1;i<=n;i++){
                if(k==0)
                    dp[i][k]=num[i];
                else
                    dp[i][k]=dp[i-1][k-1]*num[i];
                dp[i][k]+=dp[i-1][k];
                dp[i][k]%=m;
            }
        }
        ll ans=dp[n][0];
        for(int i=1;i<=n;i++)
            ans=max(ans,dp[n][i]);
        cout<<ans<<"\n";
    }
    return 0;
}
