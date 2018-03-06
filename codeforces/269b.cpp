#include<bits/stdc++.h>
using namespace std;
#define maxn 5005
int dp[maxn];
int type[maxn];
int main() {
    int n, m;
    scanf ( "%d%d", &n, &m );
    for ( int i = 1; i <= n; i++ ) {
        double x;
        scanf ( "%d%lf", &type[i], &x );
    }
    for ( int i = 1; i <= n; i++ ) {
        int j = type[i];
        for ( int k = j; k >= 1; k-- ) {
            dp[j] = max ( dp[j], 1 + dp[k] );
            //     printf("j=%d k=%d dp[j]=%d\n",j,k,dp[j]);
        }
    }
    int ans = 0;
    for ( int i = 1; i <= m; i++ ) {
        ans = max ( ans, dp[i] );
    }
    printf ( "%d\n", n - ans );
    return 0;
}
