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
const ll MOD=1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ll i,n,m;
    cin>>n>>m;
    int ans=((n%MOD)*(m%MOD))%MOD;
    int sum=0;
    m=min(n,m);
    for(i=1;i<=m;i++){
        ll r=n/(n/i);
//        cout<<"r= "<<r<<endl;
        r=min(m,r);
        ll cnt=r-i+1;
        ll tt=i+r;
//        cout<<"cnt= "<<cnt<<" tt= "<<tt<<endl;
        if(tt%2==0){
            tt=(((tt/2)%MOD)*(cnt%MOD))%MOD;
        }else
            tt=((tt%MOD)*((cnt/2)%MOD))%MOD;
//        cout<<"tt "<<tt<<endl;
        tt=((tt%MOD)*((n/i)%MOD))%MOD;
        sum=(sum%MOD+tt%MOD)%MOD;
//        cout<<"sum= "<<sum<<endl;
        i=r;
    }
    ans=((ans%MOD)-(sum%MOD))%MOD;
    if(ans<0)
        ans=ans+MOD;
    cout<<ans<<endl;
    return 0;
}
