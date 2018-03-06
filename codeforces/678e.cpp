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
#include <iomanip>
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
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=20;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a){return a<-eps? -1:a>eps;}

int n;
double p[maxn][maxn];
double dp[20][(1<<18)+10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>p[i][j];
    }
    dp[0][1]=1;
    for(int i=1;i<n;i++){
        dp[i][1<<i]=0;
    }
    for(int U=2;U<(1<<n);U++){
        for(int i=0;i<n;i++){
            if(U&(1<<i)){
                for(int j=0;j<n;j++){
                    if(j==i)
                        continue;
                    if(U&(1<<j)){
                        dp[i][U]=max(dp[i][U],p[i][j]*dp[i][U&(((1<<n)-1)-(1<<j))]+p[j][i]*dp[j][U&(((1<<n)-1)-(1<<i))]);
                    }
                }
            }
        }
    }
    double ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i][(1<<n)-1]);
    }
    cout<<fixed<<setprecision(8)<<ans<<endl;
    return 0;
}
