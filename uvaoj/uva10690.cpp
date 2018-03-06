#include<bits/stdc++.h>
using namespace std;
#define maxn 105

bool dp[maxn][maxn*maxn];
int n,m;
int a[maxn];
int sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>m) {
        memset(dp,false,sizeof(dp));
        sum=0;
        for(int i=1; i<=n+m; i++)
            cin>>a[i];
        for(int i=1; i<=n+m; i++) {
            sum+=a[i];
            a[i]+=50;
        }
        dp[0][0]=true;
        for(int i=1; i<=n+m; i++) {
            int ti=min(i,n);
            for(int j=ti; j>=1; j--) {
                for(int k=0; k<=10000; k++) {
                    if(dp[j-1][k])
                        dp[j][k+a[i]]=true;
                }
            }
        }
        int maxx=INT_MIN;
        int minn=INT_MAX;
        for(int i=0;i<=10000;i++){
            if(dp[n][i]){
                int t=i-50*n;
                maxx=max(maxx,t*(sum-t));
                minn=min(minn,t*(sum-t));
            }
        }
        cout<<maxx<<" "<<minn<<"\n";
    }
    return 0;
}
