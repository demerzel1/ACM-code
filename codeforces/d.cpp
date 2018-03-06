#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int mp[maxn*2][maxn*2];
int n;
int dp[4][maxn*2][maxn*2];

int main() {
    int T;
    cin>>T;
    while(T--) {
        cin>>n;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                cin>>mp[i][j];
                mp[i+n][j]=mp[i][j];
                mp[i][j+n]=mp[i][j];
                mp[i+n][j+n]=mp[i][j];
            }
        }
        int maxx=INT_MIN;
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=2*n; i++) {
            for(int j=1; j<=2*n; j++) {
                if(dp[0][i][j-1]+mp[i][j]>0)
                    dp[0][i][j]=dp[0][i][j-1]+mp[i][j];
                else
                    dp[0][i][j]=0;
                if(dp[1][i-1][j]+mp[i][j]>0)
                    dp[1][i][j]=dp[1][i-1][j]+mp[i][j];
                else
                    dp[1][i][j]=0;
                if(dp[2][i-1][j-1]+mp[i][j]>0)
                    dp[2][i][j]=dp[2][i-1][j-1]+mp[i][j];
                else
                    dp[2][i][j]=0;
                if(dp[3][i-1][j+1]+mp[i][j]>0)
                    dp[3][i][j]=dp[3][i-1][j+1]+mp[i][j];
                else
                    dp[3][i][j]=0;
                int t1=dp[0][i][j];
                int t2=dp[1][i][j];
                int t3=dp[2][i][j];
                int t4=dp[3][i][j];
//                if(i==7&&j==4||i==3&&j==4)
//                    cout<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<"\n";
                if(i>n&&j>n) {
                    t3-=dp[2][i-n][j-n];
                }
                if(i>n){
                    t2-=dp[1][i-n][j];
                }
                if(j>n){
                    t1-=dp[0][i][j-n];
                }
                if(i>n&&j<=n)
                    t4-=dp[3][i-n][j];
//                 if(i==7&&j==4||i==3&&j==4)
//                    cout<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<"\n";
                maxx=max(maxx,max(max(t1,t2),max(t3,t4)));
//                cout<<maxx<<"\n";
//                if(maxx==30)
//                    cout<<i<<" "<<j<<"\n";
            }
        }
        cout<<maxx<<"\n";
    }
    return 0;
}




/*
5
4
10 0 0 9
0 0 0 0
0 2 0 0
12 0 0 10
4
10 0 0 9
0 0 0 0
0 2 0 0
12 0 0 10
5
0 0 0 10 1
0 0 0 0 0
0 20 10 0 0
0 10 1 10 0
1 0 0 11 0

*/
