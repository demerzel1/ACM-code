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
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a){return a<-eps? -1:a>eps;}

int n;
map<int,int> mp,use;
int p[maxn];
int cnt;
int a[maxn];


void init(){
    ll t=2;
    while(t<(ll)(2e9+10)){
        p[cnt]=(int)t;
        cnt++;
        t*=2;
    }
}
ll ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n;
    init();
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    for(int i=0;i<n;i++){
        mp[a[i]]--;
        for(int j=0;j<cnt;j++){
       //     cout<<p[j]<<endl;
            int t=p[j]-a[i];
            ans+=mp[t];
        }
    }
    cout<<ans<<endl;
    return 0;
}