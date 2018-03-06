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

const int maxn = 10010;

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

int n;

void init () {
    tot = 0;
    memset(head, -1, sizeof(head));
    pos = 0;
    memset(son, 0, sizeof(son));
//    memset(sz,0,sizeof(sz));
    memset(top,0,sizeof(top));
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

    void pushup (int o) {
        data[o] = max(data[ls], data[rs]);
    }

    void build (int o, int l, int r) {
        if (l == r) {
            data[o] = val[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(o);
    }

    void update (int o, int l, int r, int index, T v) {
        if (l == r) {
            data[o] = v;
            return;
        }
        int mid = (l + r) >> 1;
        if (index <= mid) update(ls, l, mid, index, v);
        else update(rs, mid + 1, r, index, v);
        pushup(o);
    }

    T query (int o, int l, int r, int x, int y) {
        if (l >= x && r <= y) {
            return data[o];
        }
        int mid = (l + r) >> 1;
        if (y <= mid) return query(ls, l, mid, x, y);
        if (x > mid) return query(rs, mid + 1, r, x, y);
        return max(query(ls, l, mid, x, y), query(rs, mid + 1, r, x, y));
    }
};

int e[maxn][4];

Segtree<int> tree;

int solve (int va, int vb) {
    int f1 = top[va];
    int f2 = top[vb];
    int res = 0;
    while (f1 != f2) {
        if (dep[f1] < dep[f2]) {
            swap(f1, f2);
            swap(va, vb);
        }
        res = max(res, tree.query(1, 1, pos, w[f1], w[va]));
        va = fa[f1];
        f1 = top[va];
    }
    if (va == vb)
        return res;
    if (dep[va] > dep[vb])
        swap(va, vb);
    res = max(res, tree.query(1, 1, pos, w[son[va]], w[vb]));
    return res;
}

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        init();
        scanf("%d", &n);
        for (int i = 1; i <= n - 1; i++) {
            scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2]);
            addedge(e[i][0], e[i][1]);
            addedge(e[i][1], e[i][0]);
        }
        dfs1(1, 0, 0);
        dfs2(1, 0);
        for (int i = 1; i <= n - 1; i++) {
            if (dep[e[i][0]] < dep[e[i][1]])
                swap(e[i][0], e[i][1]);
            val[w[e[i][0]]] = e[i][2];
        }
        tree.build(1, 1, pos);
        char op[10];
        int u, v;
        while (~scanf("%s", op)) {
            if (op[0] == 'D')
                break;
            scanf("%d%d", &u, &v);
            if (op[0] == 'Q') {
                printf("%d\n", solve(u, v));
            } else {
                tree.update(1, 1, pos, w[e[u][0]], v);
            }
        }
    }
    return 0;
}