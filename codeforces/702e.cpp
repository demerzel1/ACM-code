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

const int maxn=100005;
const int maxm=40;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a){return a<-eps? -1:a>eps;}

ll path[maxn][maxm];
ll sum[maxn][maxm];
int minn[maxn][maxm];
int n;
ll k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>path[i][0];
    for(int i=0;i<n;i++){
        cin>>minn[i][0];
        sum[i][0]=(ll)minn[i][0];
    }
    for(int j=1;j<=35;j++){
        for(int i=0;i<n;i++){
            path[i][j]=path[path[i][j-1]][j-1];
            sum[i][j]=sum[i][j-1]+sum[path[i][j-1]][j-1];
            minn[i][j]=min(minn[i][j-1],minn[path[i][j-1]][j-1]);
        }
    }
    for(int i=0;i<n;i++){
        int t=INF;
        ll ans=0;
        int now=i;
        for(int j=0;j<=35;j++){
            if((1LL<<j)&k){
                t=min(t,minn[now][j]);
                ans+=sum[now][j];
                now=path[now][j];
           //     cout<<now<<endl;
            }
        }
        cout<<ans<<' '<<t<<endl;
    }
    return 0;
}