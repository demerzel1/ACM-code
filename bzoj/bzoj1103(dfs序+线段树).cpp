#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=250010;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;

template<class T>inline bool read(T&x){
    int c;
    for(c=getchar();~c&&c<33;c=getchar());
    if(!(~c)) return false;
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
    return true;
}

int n,m;
vector<int> g[maxn];
int in[maxn];
int out[maxn];
bool vis[maxn];
int val[maxn];
int dfs_clock;

void dfs(int x,int d){
    in[x]=++dfs_clock;
    val[dfs_clock]=d;
    vis[x]=true;
    for(int i=0;i<g[x].size();++i){
        if(!vis[g[x][i]])
            dfs(g[x][i],d+1);
    }
    out[x]=dfs_clock;
}


template<class T>struct Segtree {
#define ls (o<<1)
#define rs (o<<1)|1
    T data[maxn<<2];
    T lazy[maxn<<2];
    void pushup(int o) {
        data[o]=data[ls]+data[rs];
    }
    void setlazy(int o,int m,T v) {
        lazy[o]+=v;
        data[o]+=m*v;
    }
    void pushdown(int o,int m) {
        if(lazy[o]) {
            setlazy(ls,m-(m>>1),lazy[o]);
            setlazy(rs,m>>1,lazy[o]);
            lazy[o]=0;
        }
    }
    void build(int o,int l,int r) {
        lazy[o]=0;
        if(l==r) {
            data[o]=val[l];
            return;
        }
        int mid=(l+r)>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        pushup(o);
    }

    void update(int o,int l,int r,int x,int y,T v) {
        if(l>=x && r<=y) {
            setlazy(o,r-l+1,v);
            return;
        }
        pushdown(o,r-l+1);
        int mid=(l+r)>>1;
        if(x<=mid) update(ls,l,mid,x,y,v);
        if(y>mid)  update(rs,mid+1,r,x,y,v);
        pushup(o);
    }
    T query(int o,int l,int r,int x,int y) {
        if(l>=x && r<=y) {
            return data[o];
        }
        pushdown(o,r-l+1);
        int mid=(l+r)>>1;
        if(y<=mid) return query(ls,l,mid,x,y);
        if(x>mid)  return query(rs,mid+1,r,x,y);
        return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);
    }
};

Segtree<int> tree;

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&n);
    int a,b;
    for(int i=1;i<n;++i){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    tree.build(1,1,n);
    scanf("%d",&m);
    char op[2];
//    printf("%d\n",n+m-1);
    for(int i=1;i<=n+m-1;++i){
        scanf("%s",op);
//        printf("op=%s\n",op);
        if(op[0]=='A'){
            int a,b;
            scanf("%d%d",&a,&b);
            if(val[in[a]]<val[in[b]])
                swap(a,b);
            tree.update(1,1,n,in[a],out[a],-1);
        }else{
            int a;
            scanf("%d",&a);
            printf("%d\n",tree.query(1,1,n,in[a],in[a]));
        }
    }
    return 0;
}