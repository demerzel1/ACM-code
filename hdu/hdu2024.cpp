#include<bits/stdc++.h>
using namespace std;
#define maxn 3005
using ll=long long;
struct node{
    int x;
    int c;
    node(int a=0,int b=0){
        x=a;
        c=b;
    }
};
struct node shu[maxn];
bool cmp(struct node &a,struct node &b){
    return a.x<b.x;
}

ll dp[maxn][maxn];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
                dp[i][j]=LLONG_MAX;
        }
        memset(shu,0,sizeof(shu));
        for(int i=1;i<=n;i++)
            scanf("%d%d",&shu[i].x,&shu[i].c);
        sort(shu+1,shu+n+1,cmp);
        dp[1][1]=(ll)shu[1].c;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i][j]=dp[i-1][j]+(ll)(shu[i].x-shu[j].x);
                dp[i][i]=min(dp[i][i],dp[i-1][j]+(ll)shu[i].c);
            }
        }
        ll ans=LLONG_MAX;
        for(int i=1;i<=n;i++)
            ans=min(ans,dp[n][i]);
        cout<<ans<<"\n";
    }
    return 0;
}
