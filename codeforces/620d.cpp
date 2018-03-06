By demerzel, contest: Educational Codeforces Round 6, problem: (D) Professor GukiZ and Two Arrays, Accepted, #
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

const int maxn=2005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a) {
    return a<-eps? -1:a>eps;
}

struct node {
    int x;
    int y;
    ll val;
    node(int a,int b,ll c) {
        x=a;
        y=b;
        val=c;
    }
};
bool operator <(const node &a,const node &b) {
    return a.val<b.val;
}

int n,m;
ll a[maxn];
ll b[maxn];
ll s;
ll ans=LLONG_MAX;
vector<node> aij;
vector<node> bij;
int inda1=-1,indb1=-1;
int inda2=-1,indb2=-1;
int type=0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        s+=a[i];
    }
    cin>>m;
    for(int i=0; i<m; i++) {
        cin>>b[i];
        s-=b[i];
    }
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            aij.push_back(node(i,j,a[i]+a[j]));
        }
    }
    for(int i=0; i<m; i++) {
        for(int j=i+1; j<m; j++) {
            bij.push_back(node(i,j,2ll*b[i]+2ll*b[j]));
        }
    }
    ans=abs(s);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(abs(s-2ll*a[i]+2ll*b[j])<ans) {
                type=1;
                ans=abs(s-2ll*a[i]+2ll*b[j]);
                inda1=i;
                indb1=j;
            }
        }
    }
    sort(bij.begin(),bij.end());
    for(int i=0; i<aij.size(); i++) {
        ll t=2ll*aij[i].val-s;
        node tt=node(0,0,t);
        int jj=lower_bound(bij.begin(),bij.end(),tt)-bij.begin();
        int sz=bij.size();
        for(int j=max(0,jj-2); j<=min(jj+2,sz-1); j++) {
            if(abs(bij[j].val-t)<ans) {
                ans=abs(bij[j].val-t);
                inda1=aij[i].x;
                inda2=aij[i].y;
                indb1=bij[j].x;
                indb2=bij[j].y;
                type=2;
            }
        }
    }

    if(type==0) {
        cout<<ans<<endl;
        cout<<"0\n";
    } else if(type==1) {
        cout<<ans<<endl;
        cout<<type<<endl;
        cout<<inda1+1<<' '<<indb1+1<<endl;
    } else if(type==2) {
        cout<<ans<<endl;
        cout<<type<<endl;
        cout<<inda1+1<<' '<<indb1+1<<endl;
        cout<<inda2+1<<' '<<indb2+1<<endl;
    }
    return 0;
}
