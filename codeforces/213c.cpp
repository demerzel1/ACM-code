#include<bits/stdc++.h>
using namespace std;
#define maxn 305
#define INF 100000000
int dp[2*maxn][maxn][maxn];

int mp[maxn][maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    memset(dp,0xf3,sizeof(dp));
    dp[1][1][1]=mp[1][1];
    for(int i=2;i<=n+n-1;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dp[i][j][k]=max(max(dp[i-1][j][k],dp[i-1][j-1][k]),max(dp[i-1][j][k-1],dp[i-1][j-1][k-1]));
              //  printf("dp=%d\n",dp[i][j][k]);
                if(j==k){
                    dp[i][j][k]+=mp[j][i-j+1];
               //     printf("%d %d %d %d \n",i,j,k,dp[i][j][k]);
                }else{
                    dp[i][j][k]+=mp[j][i-j+1]+mp[k][i-k+1];
              //      printf("%d %d %d %d \n",i,j,k,dp[i][j][k]);
                }
            }
        }
    }
    printf("%d",dp[n+n-1][n][n]);
    return 0;
}
