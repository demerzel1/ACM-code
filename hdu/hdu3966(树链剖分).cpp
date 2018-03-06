#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;


const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-9;

const int maxn = 50010;

int n,m,p;
int a[maxn];


struct Edge {
    int to;
    int next;
} edge[maxn * 2];

int head[maxn], tot;  //图

int sz[maxn]; //sz[v]为以v为根的子树的size
int dep[maxn];//v的深度
int top[maxn];//v所在的重链的顶端节点
int son[maxn];//v的重儿子
int fa[maxn];//v的父节点
int w[maxn];//v和父节点的连边在线段树的位置
int val[maxn];//剖分后的边的权值
int pos;
int e[maxn][3];

void init () {
    tot = 0;
    memset(head, -1, sizeof(head));
    pos = 0;
    memset(son, 0, sizeof(son));
    memset(top,0,sizeof(top));
}

void addedge (int u, int v) {
    edge[++tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot;
};


void dfs1 (int u, int pre, int d) {
    dep[u] = d;
    fa[u] = pre;
    sz[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (v != pre) {
            dfs1(v, u, d + 1);
            sz[u] += sz[v];
            if (son[u] == 0 || sz[v] > sz[son[u]]) {
                son[u] = v;
            }
        }
    }
}

void dfs2 (int u, int tp) {
    top[u] = tp;//记录u所在重链的头结点
    w[u] = ++pos;
    if (son[u] != 0)
        dfs2(son[u], top[u]);
    for (int i = head[u]; i != -1; i = edge[i].next) {
        if (edge[i].to != son[u] && edge[i].to != fa[u]) {
            dfs2(edge[i].to, edge[i].to);
        }
    }
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

void solve(int va,int vb,int c){
    int f1 = top[va];
    int f2 = top[vb];
    while (f1 != f2) {
        if (dep[f1] < dep[f2]) {
            swap(f1, f2);
            swap(va, vb);
        }
        tree.update(1,1,pos,w[f1],w[va],c);
        va = fa[f1];
        f1 = top[va];
    }
    if (va == vb){
        //点权转化边权，需要更新va点
        tree.update(1,1,pos,w[va],w[va],c);
        return;
    }
    if (dep[va] > dep[vb])
        swap(va, vb);
    tree.update(1,1,pos,w[va],w[vb],c);
    return;
}

int main(){
    while(~scanf("%d%d%d",&n,&m,&p)){
        init();
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        for(int i=1;i<=m;i++){
            scanf("%d%d",&e[i][0],&e[i][1]);
            addedge(e[i][0],e[i][1]);
            addedge(e[i][1],e[i][0]);
        }
        dfs1(1,0,0);
        dfs2(1,0);
        for(int i=1;i<=n;i++){
            val[w[i]]=a[i];
        }
        tree.build(1,1,pos);
        char op[5];
        while(p--){
            int _1,_2,_3;
            scanf("%s",op);
            if(op[0] == 'I'){
                scanf("%d%d%d",&_1,&_2,&_3);
                solve(_1,_2,_3);
            }else if(op[0]=='D'){
                scanf("%d%d%d",&_1,&_2,&_3);
                solve(_1,_2,-_3);
            }else if(op[0]=='Q'){
                scanf("%d",&_1);
                int ans=tree.query(1,1,pos,w[_1],w[_1]);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}