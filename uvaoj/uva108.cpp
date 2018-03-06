#include<bits/stdc++.h>
using namespace std;
#define maxn 105

int a[maxn][maxn];
int s[maxn][maxn];
int dp[maxn];
int n;
int ans;

int main(){
    while(cin>>n){
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
                s[i][j]=s[i-1][j]+a[i][j];
            }
        ans=s[1][1];
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int t=0;
                for(int k=1;k<=n;k++){
                    if(t<0)
                        t=s[j][k]-s[i][k];
                    else
                        t+=s[j][k]-s[i][k];
                    ans=max(ans,t);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
