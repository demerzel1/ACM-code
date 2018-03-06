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
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a) {
    return a<-EPS? -1:a>EPS;
}

struct node {
    ll v;
    int id;
    int date;
    node(ll a=0,int b=0,int c=0) {
        v=a;
        id=b;
        date=c;
    }
};

bool cmp(node x,node y) {
    return x.v<y.v;
}

int n,m,k;
ll s;
ll a[maxn];
ll b[maxn];
int t[maxn];
ll c[maxn];
int p1[maxn];
int p2[maxn];
vector<node> ans;

bool judge(int x) {
    ans.clear();
//    cout<<x<<" "<<p1[x]<<" "<<p2[x]<<"\n";
    for(int i=1; i<=m; i++) {
        if(t[i]==1) {
            node xx=node((ll)(a[p1[x]]*c[i]),i,p1[x]);
//            cout<<a[p1[x]]*c[i]<<"aaa\n";
            ans.push_back(xx);
        } else {
            node xx=node((ll)(b[p2[x]]*c[i]),i,p2[x]);
            ans.push_back(xx);
        }
//        cout<<ans.back().v<<"\n";
    }
    sort(ans.begin(),ans.end(),cmp);
    ll sum=0;
    for(int i=0; i<k; i++) {
//        cout<<ans[i].v<<" "<<i<<"\n";
        sum+=ans[i].v;
    }
//    cout<<sum<<"\n";
    return sum<=s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k>>s;
    p1[0]=1;
    p2[0]=1;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
        if(a[i]<a[p1[i-1]]) {
            p1[i]=i;
        } else
            p1[i]=p1[i-1];
    }
    for(int i=1; i<=n; i++) {
        cin>>b[i];
        if(b[i]<b[p2[i-1]])
            p2[i]=i;
        else
            p2[i]=p2[i-1];
    }
    for(int i=1; i<=m; i++) {
        cin>>t[i]>>c[i];
    }
    int l=0;
    int r=n+1;
    int mid;
    while(l+1<r) {
        mid=(l+r)>>1;
        if(judge(mid)) {
            r=mid;
        } else
            l=mid;
    }
    if(r==n+1) {
        cout<<-1<<"\n";
        return 0;
    }
    judge(r);
    int tt=0;
    for(int i=0;i<k;i++){
        tt=max(tt,ans[i].date);
    }
    cout<<tt<<"\n";
    for(int i=0; i<k; i++) {
        cout<<ans[i].id<<" "<<ans[i].date<<"\n";
    }
    return 0;
}
