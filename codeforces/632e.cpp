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

const int maxn=1005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a){return a<-eps? -1:a>eps;}

int n,k;
int a[maxn];
int dp[maxn*maxn];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    n=unique(a,a+n)-a;
    n--;
  //  cout<<n<<endl;
    for(int i=1;i<=n;i++)
        a[i]-=a[0];
    for(int i=1;i<=a[n]*k;i++){
        dp[i]=k+1;
    }
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=a[i];j<=a[i]*k;j++){
            dp[j]=min(dp[j],dp[j-a[i]]+1);
        }
    }
    for(int i=0;i<=a[n]*k;i++){
        //cout<<i<<' '<<dp[i]<<endl;
        if(dp[i]<=k){
            cout<<i+a[0]*k<<' ';
        }
    }
    return 0;
}
