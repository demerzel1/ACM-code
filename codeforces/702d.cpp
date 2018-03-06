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

ll d,k,a,b,t;
ll ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>d>>k>>a>>b>>t;
    if(d<=k){
        ans=a*d;
        cout<<ans<<endl;
        return 0;
    }
    ans+=a*k;
    d-=k;
//    if(k*b<=k*a+t){
//        ans+=d*b;
//        cout<<ans<<endl;
//        return 0;
//    }
    ll t1=d/k;
    ll t2=d%k;
    ans+=min(t1*(k*a+t),t1*k*b);
    ans+=min(t2*a+t,t2*b);
    cout<<ans<<endl;
    return 0;
}