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

const int maxn=200005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
const ll mod=1e9+7;
inline int sgn(double a) {
    return a<-eps? -1:a>eps;
}

ll quickpow(ll  m,ll n,ll k) {
    ll b = 1;
    while(n > 0) {
        if(n & 1)
            b = (b*m)%k;
        n = n >> 1;
            m = (m*m)%k;
    }
    return b;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ll n,m;
    cin>>n>>m;
    ll ans=quickpow(m,n,mod);
    for(int i=1;i<=n;i++){
        ans=(ans+quickpow(m,n-i+1,mod)*quickpow(2*m-1,i-1,mod))%mod;
    }
    cout<<ans<<endl;
    return 0;
}
