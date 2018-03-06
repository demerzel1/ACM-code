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
inline int sgn(double a){return a<-eps? -1:a>eps;}

ll n,a,b,p,q;
ll gcd(ll a,ll b){
    if(!a)return 1;if(!b)return a;
    if(a<0) a=-a; for(ll t;b;t=a%b,a=b,b=t);
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n>>a>>b>>p>>q;
    ll ans=(n/a)*p+(n/b)*q;
    ll lcm=a*b/gcd(a,b);
    if(p>q)
        ans-=(n/lcm)*q;
    else
        ans-=(n/lcm)*p;
    cout<<ans<<endl;
    return 0;
}