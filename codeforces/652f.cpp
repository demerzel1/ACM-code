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

const int maxn=300005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

ll n,m,t;
struct node{
    ll p;
    int id;
    int f;
}ant[maxn];
ll tp[maxn];
ll ans[maxn];

bool cmp(node a,node b){
    return a.p<b.p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n>>m>>t;
    string st;
    for(int i=0;i<n;i++){
        cin>>ant[i].p>>st;
        ant[i].p--;
//        cout<<p[i]<<endl;
        if(st=="L")
            ant[i].f=-1;
        else
            ant[i].f=1;
        ant[i].id=i;
    }
    sort(ant,ant+n,cmp);
    ll s=0;
    for(int i=0;i<n;i++){
        if(ant[i].f==1){
            s=(s+(ant[i].p+t)/m)%n;
            tp[i]=(ant[i].p+t)%m;
        }else{
            s=(s+(ant[i].p-t)/m)%n;
            tp[i]=(ant[i].p-t)%m;
            if(tp[i]<0){
                tp[i]+=m;
                s=((s-1)%n+n)%n;
            }
        }
//        cout<<p[i]<<endl;
    }
    s=(s%n+n)%n;
    sort(tp,tp+n);
    int ind=0;
    for(int i=s;i<n;i++){
        ans[ant[ind++].id]=tp[i];
//        cout<<p[i]<<endl;
    }
    for(int i=0;i<s;i++)
        ans[ant[ind++].id]=tp[i];
    for(int i=0;i<n;i++)
        cout<<ans[i]+1<<' ';
    return 0;
}
