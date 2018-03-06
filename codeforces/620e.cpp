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

const int maxn=400005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a){return a<-eps? -1:a>eps;}

int n,m;
vector<int> g[maxn];
int col[maxn];
int ind;
int xu[maxn][2];
bool vis[maxn];
int fan[maxn];

void dfs(int x){
    xu[x][0]=++ind;
    fan[ind]=x;
    vis[x]=true;
    for(int i=0;i<g[x].size();i++){
        int u=g[x][i];
        if(vis[u])
            continue;
        dfs(u);
    }
    xu[x][1]=ind;
}
struct seg_tree{
    #define ls (o<<1)
    #define rs ((o<<1)|1)
    ll data[maxn<<2];
    int lazy[maxn<<2];

    void pushup(int o){
        data[o]=data[ls]|data[rs];
    }
    void pushdown(int o){
        if(lazy[o]){
            lazy[ls]=lazy[rs]=lazy[o];
            data[ls]=data[rs]=1LL<<lazy[o];
            lazy[o]=0;
        }
    }
    void build(int o,int l,int r){
        lazy[o]=0;
        if(l==r){
            data[o]=1LL<<(col[fan[l]]);
            return;
        }
        int mid=(l+r)>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        pushup(o);
    }
    void update(int o,int l,int r,int x,int y,int v){
        if(l>=x && r<=y){
            data[o]=1LL<<v;
            lazy[o]=v;
            return;
        }
        int mid=(l+r)>>1;
        pushdown(o);
        if(x<=mid)  update(ls,l,mid,x,y,v);
        if(y>mid)   update(rs,mid+1,r,x,y,v);
        pushup(o);
    }
    ll query(int o,int l,int r,int x,int y){
        if(l>=x&&r<=y){
            return data[o];
        }
        pushdown(o);
        int mid=(l+r)>>1;
        if(y<=mid) return query(ls,l,mid,x,y);
        if(x>mid)  return query(rs,mid+1,r,x,y);
        return query(ls,l,mid,x,y)|query(rs,mid+1,r,x,y);
    }
};
struct seg_tree tree;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>col[i];
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);

    tree.build(1,1,n);
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int x,c;
            cin>>x>>c;
            tree.update(1,1,n,xu[x][0],xu[x][1],c);
        }else{
            int x;
            cin>>x;
            ll ans=tree.query(1,1,n,xu[x][0],xu[x][1]);
            int cnt=0;
            while(ans){
                if(ans&1)
                    cnt++;
                ans>>=1;
            }
            cout<<cnt<<endl;

        }
    }
    return 0;
}
