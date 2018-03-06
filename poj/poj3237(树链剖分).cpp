#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <iomanip>
#include <set>
#include <complex>
#include <cstring>
#include <cstdio>
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

int n;
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
int e[maxn][4];

void init () {
    tot = 0;
    memset(head, -1, sizeof(head));
    pos = 0;
    memset(son, 0, sizeof(son));
    memset(top, 0, sizeof(top));
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

template<class T>
struct Segtree {
#define ls (o<<1)
#define rs (o<<1)|1
    T data[maxn << 2];
    T data1[maxn << 2];
    T lazy[maxn << 2];

    void pushup (int o) {
        data[o] = max(data[ls], data[rs]);
        data1[o] = min(data1[ls], data1[rs]);
    }

    void setlazy (int o) {
        lazy[o] ^= 1;
        swap(data[o],data1[o]);
        data[o]*=-1;
        data1[o]*=-1;
    }

    void pushdown (int o) {
        if (lazy[o]) {
            setlazy(ls);
            setlazy(rs);
            lazy[o] = 0;
        }
    }

    void build (int o, int l, int r) {
        lazy[o] = 0;
        if (l == r) {
            data[o] = val[l];
            data1[o] = val[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(o);
    }

    void update (int o, int l, int r, int x, int y) {
        if (l >= x && r <= y) {
            setlazy(o);
            return;
        }
        pushdown(o);
        int mid = (l + r) >> 1;
        if (x <= mid) update(ls, l, mid, x, y);
        if (y > mid) update(rs, mid + 1, r, x, y);
        pushup(o);
    }

    void updateone (int o, int l, int r, int index, T v) {
        if (l == r) {
            data[o] = v;
            data1[o] = v;
            return;
        }
        pushdown(o);
        int mid = (l + r) >> 1;
        if (index <= mid) updateone(ls, l, mid, index, v);
        else updateone(rs, mid + 1, r, index, v);
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
        return max(query(ls, l, mid, x, y), query(rs, mid + 1, r, x, y));
    }
};

Segtree<int> tree;

void solve (int va, int vb) {
    int f1 = top[va];
    int f2 = top[vb];
   // printf("f1=%d f2=%d\n",f1,f2);
    while (f1 != f2) {
        if (dep[f1] < dep[f2]) {
            swap(f1, f2);
            swap(va, vb);
        }
        tree.update(1, 1, pos, w[f1], w[va]);
        va = fa[f1];
        f1 = top[va];
    }
    if (va == vb) {
        return;
    }
    if (dep[va] > dep[vb])
        swap(va, vb);
  //  printf("va=%d vb=%d\n",va,vb);
    tree.update(1, 1, pos, w[son[va]], w[vb]);
    return;
}


int solve1 (int va, int vb) {
  //  printf("query:\n");
    int f1 = top[va];
    int f2 = top[vb];
  //  printf("f1=%d f2=%d\n",f1,f2);
    int res = -INF;
    while (f1 != f2) {
        if (dep[f1] < dep[f2]) {
            swap(f1, f2);
            swap(va, vb);
        }
        res = max(res, tree.query(1, 1, pos, w[f1], w[va]));
        va = fa[f1];
        f1 = top[va];
    }
    if (va == vb) {
        return res;
    }
    if (dep[va] > dep[vb])
        swap(va, vb);
  //  printf("va=%d vb=%d\n",va,vb);
    res = max(res, tree.query(1, 1, pos, w[son[va]], w[vb]));
    return res;
}

int main () {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d", &n);
        for (int i = 1; i < n; i++) {
            scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2]);
            addedge(e[i][0], e[i][1]);
            addedge(e[i][1], e[i][0]);
        }
        // printf("222\n");
        dfs1(1, 0, 0);
        dfs2(1, 0);
        for (int i = 1; i < n; i++) {
            if (dep[e[i][0]] < dep[e[i][1]])
                swap(e[i][0], e[i][1]);
            val[w[e[i][0]]] = e[i][2];
        }

        son[0]=1;
        tree.build(1, 1, pos);
        //  printf("111\n");
        char op[10];
        int _1, _2;
        while (~scanf("%s", op)) {
            if (op[0] == 'D') {
                break;
            }
            if (op[0] == 'C') {
                scanf("%d%d", &_1, &_2);
                tree.updateone(1, 1, pos, w[e[_1][0]], _2);
            } else if (op[0] == 'N') {
                scanf("%d%d", &_1, &_2);
                solve(_1, _2);
            } else if (op[0] == 'Q') {
                scanf("%d%d", &_1, &_2);
                int ans = solve1(_1, _2);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}

/*
1

3
1 2 1
2 3 2
QUERY 1 2
CHANGE 1 3
NEGATE 1 3
QUERY 1 2
DONE
 */