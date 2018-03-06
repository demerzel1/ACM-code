#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
int N;
int a[maxn];
int dp[maxn];

int main(){
    while(cin>>N&&N){
        for(int i=1;i<=N;i++)
            cin>>a[i];
        memset(dp,0,sizeof(dp));
        int ans=-1;
        for(int i=1;i<=N;i++){
            dp[i]=max(dp[i-1]+a[i],a[i]);
            ans=max(dp[i],ans);
        }
        if(ans>0)
            cout<<"The maximum winning streak is "<<ans<<".\n";
        else
            cout<<"Losing streak.\n";
    }
    return 0;
}
