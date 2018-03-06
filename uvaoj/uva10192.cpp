#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int dp[maxn][maxn];
string a,b;

int main() {
    //   freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int cnt=0;
    while(getline(cin,a)) {
        if(a=="#")
            break;
        cnt++;
        getline(cin,b);
        memset(dp,0,sizeof(dp));
        int la=a.length();
        int lb=b.length();
        int i=1,j=1;
        for(; i<=la; i++) {
            j=1;
            for(; j<=lb; j++) {
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                //      printf("dpi=%d j=%d dp=%d\n",i,j,dp[i][j]);
            }
        }
        int ans=dp[la][lb];
        printf("Case #%d: you can visit at most %d cities.\n",cnt,ans);
    }
    return 0;
}

