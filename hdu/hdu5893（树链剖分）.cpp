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

const int maxn = 40010;

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

int n, m;

void init () {
    tot = 0;
    memset(head, -1, sizeof(head));
    pos = 0;
    memset(son, 0, sizeof(son));
//    memset(sz,0,sizeof(sz));
    memset(top, 0, sizeof(top));
//    memset(fa,0,sizeof(fa));
//    memset(dep,0,sizeof(dep));
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
    // printf("%d %d\n",u,tp);
    top[u] = tp;//记录u所在重链的头结点
    w[u] = ++pos;
    if (son[u] != 0)
        dfs2(son[u], top[u]);
    //  printf("111\n");
    for (int i = head[u]; i != -1; i = edge[i].next) {
        if (edge[i].to != son[u] && edge[i].to != fa[u]) {
            dfs2(edge[i].to, edge[i].to);
        }
    }
}


template<class T>
struct Segtree {
#define ls (o<<1)
#define rs (o<<1)|1
    T data[maxn << 2];
    T lazy[maxn << 2];
    T lc[maxn << 2];
    T rc[maxn << 2];

    void pushup (int o) {
        if (rc[ls] == lc[rs])
            data[o] = data[ls] + data[rs] - 1;
        else
            data[o] = data[ls] + data[rs];
        lc[o]=lc[ls];
        rc[o]=rc[rs];
    }

    void setlazy (int o, T v) {
        lazy[o] = v;
        lc[o] = rc[o] = v;
        data[o] = 1;
    }
    void pushdown (int o) {
        if (lazy[o]!=-1) {
            setlazy(ls, lazy[o]);
            setlazy(rs, lazy[o]);
            lazy[o] =-1;
        }
    }

    void build (int o, int l, int r) {
        lazy[o] = -1;
        if (l == r) {
            data[o] = 1;
            lc[o] = val[l];
            rc[o] = val[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(o);
    }

    void update (int o, int l, int r, int x, int y, T v) {
        if (l >= x && r <= y) {
            setlazy(o, v);
            return;
        }
        pushdown(o);
        int mid = (l + r) >> 1;
        if (x <= mid) update(ls, l, mid, x, y, v);
        if (y > mid) update(rs, mid + 1, r, x, y, v);
        pushup(o);
    }

    T query (int o, int l, int r, int x, int y) {
        if (l >= x && r <= y) {
            return data[o];
        }
        pushdown(o);
        int mid = (l + r) >> 1;
        if (y <= mid) return query(ls, l, mid, x, y);
        if (x > mid) return query(rs, mid + 1, r, x, y);
        if (rc[ls] == lc[rs])
            return query(ls, l, mid, x, y) + query(rs, mid + 1, r, x, y) - 1;
        else
            return query(ls, l, mid, x, y) + query(rs, mid + 1, r, x, y);
    }

    T get_c (int o, int l, int r, int x, int y) {
        if (l >= x && r <= y) {
            return lc[o];
        }
        pushdown(o);
        int mid = (l + r) >> 1;
        if (y <= mid) return get_c(ls, l, mid, x, y);
        if (x > mid) return get_c(rs, mid + 1, r, x, y);
    }
};

int e[maxn][4];

Segtree<int> tree;

void solve1 (int va, int vb, int c) {
    int f1 = top[va];
    int f2 = top[vb];
    while (f1 != f2) {
        if (dep[f1] < dep[f2]) {
            swap(f1, f2);
            swap(va, vb);
        }
        tree.update(1, 1, pos, w[f1], w[va], c);
        va = fa[f1];
        f1 = top[va];
    }
    if (va == vb)
        return;
    if (dep[va] > dep[vb])
        swap(va, vb);
    tree.update(1, 1, pos, w[son[va]], w[vb], c);
    return;
}

int solve2 (int va, int vb) {
    int f1 = top[va];
    int f2 = top[vb];
    int res = 0;
    int la = -1, lb = -1;
   // printf("%d %d\n", f1, f2);
    while (f1 != f2) {
        if (dep[f1] < dep[f2]) {
            swap(f1, f2);
            swap(va, vb);
            swap(la, lb);
        }
        res += tree.query(1, 1, pos, w[f1], w[va]);
        int now_col=tree.get_c(1,1,pos,w[va],w[va]);
        if(now_col==la){
            res--;
        }
        la= tree.get_c(1, 1, pos, w[f1], w[f1]);
        va = fa[f1];
        f1 = top[va];
    }
    if (va == vb) {
        if (la==lb)
            res--;
        return res;
    }

    if (dep[va] > dep[vb]) {
        swap(va, vb);
        swap(la, lb);
    }
    res += tree.query(1, 1, pos, w[son[va]], w[vb]);
    int now_col=tree.get_c(1,1,pos,w[vb],w[vb]);
    if(now_col==lb)
        res--;
    now_col=tree.get_c(1,1,pos,w[son[va]],w[son[va]]);
    if(now_col==la)
        res--;
    if(res==-1)
        res=0;
    return res;
}

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    while (~scanf("%d%d", &n, &m)) {
        init();
        for (int i = 1; i <= n - 1; i++) {
            scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2]);
            addedge(e[i][0], e[i][1]);
            addedge(e[i][1], e[i][0]);
        }
        dfs1(1, 0, 0);
        dfs2(1, 0);
      //  cout << 111 << endl;
        for (int i = 1; i <= n - 1; i++) {
            if (dep[e[i][0]] < dep[e[i][1]])
                swap(e[i][0], e[i][1]);
            val[w[e[i][0]]] = e[i][2];
       //    printf("val=%d i=%d %d\n",val[w[e[i][0]]],w[e[i][0]],e[i][0]);
        }

        tree.build(1, 1, pos);
        char op[10];
        int u, v, c;
        for (int i = 0; i < m; i++) {
            scanf("%s", op);
            if (op[0] == 'C') {
                scanf("%d%d%d", &u, &v, &c);
                solve1(u, v, c);
            } else {
                scanf("%d%d", &u, &v);
                int ans = solve2(u, v);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}