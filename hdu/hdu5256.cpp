#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int a[maxn];
int dp[maxn];

int main(){
    int T;
    scanf("%d",&T);
    int cas=0;
    while(T--){
        cas++;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            a[i]-=i;
        }
        fill(dp,dp+n,INT_MAX);
        for(int i=0;i<n;i++)
            *upper_bound(dp,dp+n,a[i])=a[i];
        printf("Case #%d:\n",cas);
        printf("%d\n",n-(lower_bound(dp,dp+n,INT_MAX)-dp));
    }
    return 0;
}
