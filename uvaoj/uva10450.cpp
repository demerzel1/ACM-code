#include<bits/stdc++.h>
using namespace std;
#define maxn 55
typedef long long ll;
ll dp[maxn][5];
ll ans[maxn];

void init(){
    ans[1]=2;
    ans[2]=3;
    dp[2][0]=1;
    dp[2][1]=1;
    dp[2][2]=1;
    for(int i=3;i<52;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][2];
        dp[i][1]=dp[i-1][0]+dp[i-1][2];
        dp[i][2]=dp[i-1][1];
        ans[i]=dp[i][0]+dp[i][1]+dp[i][2];
     //   printf("00 %d\n01 %d\n10 %d\ni=%d ans=%d\n",dp[i][0],dp[i][1],dp[i][2],i,ans[i]);
    }
}

int main(){
    init();
    int n;
    scanf("%d",&n);
    int cnt=1;
    while(n--){
        int x;
        scanf("%d",&x);
        printf("Scenario #%d:\n%lld\n\n",cnt,ans[x]);
        cnt++;
    }
    return 0;
}


//0->00
//1->01
//2->10
