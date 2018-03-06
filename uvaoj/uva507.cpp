#include<bits/stdc++.h>
using namespace std;
#define maxn 20005
int T;
int N;
int a[maxn];
int dp[2][maxn];

int main() {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    while(cin>>T) {
        int cas=0;
        int k=T;
        while(k--) {
            cas++;
            cin>>N;
            memset(a,0,sizeof(a));
            for(int i=1; i<N; i++)
                cin>>a[i];
            memset(dp,0,sizeof(dp));
            int ans=INT_MIN;
            int ind_ans=1;
            int l_ans=1;
            dp[1][0]=1;
            for(int i=1; i<N; i++) {
                if(dp[0][i-1]+a[i]>=a[i]) {
                    dp[0][i]=dp[0][i-1]+a[i];
                    dp[1][i]=dp[1][i-1];
                } else {
                    dp[0][i]=a[i];
                    dp[1][i]=i;
                }
                if(dp[0][i]>ans) {
                    ans=dp[0][i];
                    ind_ans=i;
                    l_ans=dp[1][i];
                } else if(dp[0][i]==ans) {
                    if(i-dp[1][i]>ind_ans-l_ans) {
                        ind_ans=i;
                        l_ans=dp[1][i];
                    }
                }
            }
            //  printf("cas=%d T=%d\n",cas,T);
            // printf("%d %d %d\n",ind_ans,l_ans,ans);
            if(ans>0) {
                printf("The nicest part of route %d is between stops %d and %d\n",cas,l_ans,ind_ans+1);
            } else {
                printf("Route %d has no nice parts\n",cas);
            }
        }
    }
    return 0;
}

/*
1
6
1
-1
1
-1
1
*/
