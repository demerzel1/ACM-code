#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn = 400005;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-9;

template<class T>
inline void read (T &x) {
    int c;
    for (c = getchar(); c < 32 && ~c; c = getchar());
    for (x = 0; c > 32; x = x * 10 + c - '0', c = getchar());
}


template<class T>
struct Segtree {
#define ls (o<<1)
#define rs (o<<1)|1
    T data1[maxn << 2];
    T data2[maxn << 2];
    T lazy1[maxn << 2];
    T lazy2[maxn << 2];

    void pushup (int o) {
        data1[o] = min(data1[ls], data1[rs]);
        data2[o] = max(data2[ls], data2[rs]);
    }

    void setlazy1 (int o, T v) {
        if (v == 2) {
            lazy1[o] = 2;
            data1[o] = 0;
            data2[o] = 0;
            lazy2[o] = 0;
            return;
        }
        lazy1[o] = v;
        data1[o] = v;
        data2[o] = v;
        lazy2[o] = 0;
    }

    void setlazy2 (int o, T v) {
        lazy2[o] ^= 1;
        int t1 = 1, t2 = 0;
        if (data1[o] == 0) {
            t2 = 1;
        }
        if (data2[o] == 1) {
            t1 = 0;
        }
        data1[o] = t1;
        data2[o] = t2;
    }

    void pushdown (int o) {
        if (lazy1[o]) {
            setlazy1(ls, lazy1[o]);
            setlazy1(rs, lazy1[o]);
            lazy1[o] = 0;
        }
        if (lazy2[o]) {
            setlazy2(ls, lazy2[o]);
            setlazy2(rs, lazy2[o]);
            lazy2[o] = 0;
        }
    }

    void build (int o, int l, int r) {
        lazy1[o] = 0;
        lazy2[o] = 0;
        if (l == r) {
            data1[o] = 0;
            data2[o] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(o);
    }

    void update1 (int o, int l, int r, int x, int y, T v) {
        if (l >= x && r <= y) {
            setlazy1(o, v);
            return;
        }
        pushdown(o);
        int mid = (l + r) >> 1;
        if (x <= mid) update1(ls, l, mid, x, y, v);
        if (y > mid) update1(rs, mid + 1, r, x, y, v);
        pushup(o);
    }

    void update2 (int o, int l, int r, int x, int y, T v) {
        if (l >= x && r <= y) {
            setlazy2(o, v);
            return;
        }
        pushdown(o);
        int mid = (l + r) >> 1;
        if (x <= mid) update2(ls, l, mid, x, y, v);
        if (y > mid) update2(rs, mid + 1, r, x, y, v);
        pushup(o);
    }

    T query (int o, int l, int r, int x, int y) {
        if (l >= x && r <= y) {
            return data1[o];
        }
        pushdown(o);
        int mid = (l + r) >> 1;
        if (y <= mid) return query(ls, l, mid, x, y);
        if (x > mid) return query(rs, mid + 1, r, x, y);
        return min(query(ls, l, mid, x, y), query(rs, mid + 1, r, x, y));
    }

    int query1 (int o, int l, int r) {
        if (l==r) {
            return l;
        }
        pushdown(o);
        int mid = (l + r) >> 1;
        //   cout<<data1[ls]<<endl;
        if(data1[ls]==1)
            return query1(rs,mid+1,r);
        return query1(ls,l,mid);
    }
};

Segtree<ll> tree;

struct node{
    int o;
    ll x,y;
    node(){}
    node(int a,ll b,ll c):o(a),x(b),y(c){}
};
vector<node>v;
vector<ll>num;
int getid(ll x){
    return 1+distance(num.begin(),lower_bound(num.begin(),num.end(),x));
}


int n;
//ll query[100005][4];
//set<ll> st;
//ll hash1[400005];
//map<ll, int> mp;

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    read(n);
    for (int i = 0; i < n; i++) {
//        read(query[i][0]);
//        read(query[i][1]);
//        read(query[i][2]);
//        st.insert(query[i][1]);
//        st.insert(query[i][2]);
        ll op,x,y;
        read(op),read(x),read(y);
        v.emplace_back(op,x,y);
        num.emplace_back(x);
        num.emplace_back(y);
        num.emplace_back(y+1);
    }
    num.emplace_back(1);
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()),num.end());
    int ind=num.size();
    tree.build(1, 1, ind);
    for (const auto &t:v) {
        int type=t.o;
//        int l = mp[query[i][1]];
//        int r = mp[query[i][2]];
//        ll type = query[i][0];
        ll l=getid(t.x),r=getid(t.y);
        if (type == 1) {
            tree.update1(1, 1, ind, l, r, 1);
        } else if (type == 2) {
            tree.update1(1, 1, ind, l, r, 2);
        } else if (type == 3)
            tree.update2(1, 1, ind, l, r, 1);
//        int _l = 1, _r = ind;
//        while (_r - _l > 3) {
//            int mid = (_l + _r) >> 1;
//            if (tree.query(1, 1, ind, _l, mid) == 0) {
//                _r = mid;
//            } else if (tree.query(1, 1, ind, mid, _r) == 0) {
//                _l = mid;
//            } else
//                break;
//        }
//        int tans = _l;
//        for (; tans <= _r; tans++) {
//            if (tree.query(1, 1, ind, tans, tans) == 0) {
//                break;
//            }
//        }
//        printf("%I64d\n", hash1[tans]);
        ll tans=tree.query1(1, 1, ind);
        //  printf("tans=%d\n",tans);
        printf("%I64d\n",num[tans-1]);
    }
    return 0;
}