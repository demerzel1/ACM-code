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

const int maxn=1e6+5;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}
const ll mod=1e9+7;

int n,k;
ll a[maxn];
ll p[maxn];

ll quickpow(ll  m,ll n,ll k)
{
    ll b = 1;
    while (n > 0)
    {
          if (n & 1)
             b = (b*m)%k;
          n = n >> 1;
          m = (m*m)%k;
    }
    return b;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n>>k;
    a[0]=1;
    for(int i=1;i<maxn;i++)
        a[i]=(a[i-1]*i)%mod;
    ll ans=0;
    p[0]=0;
    for(int i=1;i<=k+2;i++){
        p[i]=(p[i-1]+quickpow(i,k,mod))%mod;
   //     cout<<p[i]<<endl;
    }
    if(n<=k+2){
        cout<<p[n]<<endl;
        return 0;
    }
    ll t=1;
    for(int i=1;i<=k+2;i++){
        t=t*(n-i)%mod;
    }
    for(int i=1;i<=k+2;i++){
        ll t1=quickpow(n-i,mod-2,mod);
        ll t2=quickpow(a[k+2-i]%mod*a[i-1]%mod,mod-2,mod);
        ll sign;
        if((k+2-i)%2==0)
            sign=1;
        else
            sign=-1;
        t2*=sign;
        ans=(ans+p[i]*t%mod*t2%mod*t1)%mod;
   //     cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
