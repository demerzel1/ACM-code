#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <climits>
#include <ctime>
#include <complex>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int>ii;
const int maxn=1111;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;

int dp[35][35][55];

int main(){
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<=30;i++){
        for(int j=0;j<=30;j++){
            for(int k=0;k<=50;k++){
                if(i*j==k||k==0){
                    dp[i][j][k]=0;
                }
                for(int m=0;m<=k;m++){
                    for(int p=1;p<i;p++){
                        dp[i][j][k]=min(dp[i][j][k],dp[p][j][m]+dp[i-p][j][k-m]+j*j);
                    }
                    for(int p=1;p<j;p++){
                        dp[i][j][k]=min(dp[i][j][k],dp[i][p][m]+dp[i][j-p][k-m]+i*i);
                    }
                }
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        cout<<dp[n][m][k]<<"\n";
    }
    return 0;
}
