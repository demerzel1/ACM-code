#include<bits/stdc++.h>
using namespace std;
#define maxn 10000

int dp[4][maxn];
int n;

void init(){
    dp[0][1]=2;
    dp[0][2]=1;
    dp[1][2]=1;
    dp[2][2]=1;
    dp[3][2]=1;
    for(int i=3;i<maxn;i++){
        dp[0][i]=dp[3][i-1];
        dp[1][i]=dp[2][i-1]+dp[1][i-1];
        dp[2][i]=dp[0][i-1]+dp[3][i-1];
        dp[3][i]=dp[1][i-1]+dp[2][i-1];
    }
}

int main(){
    init();
    while(scanf("%d",&n)&&n){
        int ans=pow(2,n);
        ans-=(dp[0][n]+dp[1][n]+dp[2][n]+dp[3][n]);
        printf("%d\n",ans);
    }
    return 0;
}
/*
uu->0
ll->1
ul->2
lu->3
*/
