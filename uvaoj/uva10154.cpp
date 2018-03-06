#include<bits/stdc++.h>
using namespace std;
#define maxn 6000
#define INF 0x7ffffff
struct turtle {
    int w;
    int s;
} t[maxn];
int ind=0;
int dp[maxn];

bool cmp(struct turtle a,struct turtle b) {
    return a.s<b.s;
}

int main() {
    while(~scanf("%d%d",&t[ind].w,&t[ind].s)) {
        ind++;
    }
    sort(t,t+ind,cmp);
    for(int i=0; i<=ind; i++)
        dp[i]=INF;
    dp[0]=0;
    int ans=0;
    for(int i=0; i<ind; i++) {
        for(int j=ans; j>=0; j--) {
            if(dp[j]+t[i].w<dp[j+1]&&dp[j]+t[i].w<t[i].s) {
                dp[j+1]=dp[j]+t[i].w;
                if(j+1>ans)
                    ans=j+1;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
