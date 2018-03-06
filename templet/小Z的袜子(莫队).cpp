#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef pair<long long, long long> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
const int maxn = 50005;
const int INF = INT_MAX;
const double pi = acos(-1.0);
const double eps = 1e-9;
template<class T>
inline T gcd (T a, T b) {
    if (!a)return 1;
    if (!b)return a;
    if (a < 0) a = -a;
    for (T t; b; t = a % b, a = b, b = t);
    return a;
}
template<class T>
inline void read (T &x) {
    int c;
    for (c = getchar(); c < 32 && ~c; c = getchar());
    for (x = 0; c > 32; x = x * 10 + c - '0', c = getchar());
}
struct node {
    int l, r, id;
    node (int a = 0, int b = 0, int c = 0) : l(a), r(b), id(c) {}
};
vector<node> query;
int pos[maxn];
int block;
int n, m;
ll a[maxn];
ll cnt[maxn];
pii ans[maxn];
ll res;
bool cmp (const node &a, const node &b) {
    if (pos[a.l] == pos[b.l])
        return a.r < b.r;
    return pos[a.l] < pos[b.l];
}
void del (int x) {
    res -= cnt[a[x]] * cnt[a[x]];
    cnt[a[x]]--;
    res += cnt[a[x]] * cnt[a[x]];
//    printf("del x=%d a[x]=%d res=%d\n",x,a[x],res);
}
void add (int x) {
    res -= cnt[a[x]] * cnt[a[x]];
    cnt[a[x]]++;
    res += cnt[a[x]] * cnt[a[x]];
//    printf("x=%d a[x]=%d res=%d\n",x,a[x],res);
}
int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    while (~scanf("%d%d", &n, &m)) {
        memset(cnt, 0, sizeof(cnt));
        query.clear();
        res = 0;
        int sz = (sqrt(n));
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            pos[i] = i / sz;
        }
        int t1, t2;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &t1, &t2);
            query.push_back(node(t1, t2, i));
        }
        sort(query.begin(), query.end(), cmp);
        int l = 1, r = 0;
        for (int ii=0;ii<query.size();ii++) {
            node &i=query[ii];
            if(i.l==i.r){
                ans[i.id].first=0;
                ans[i.id].second=1;
                continue;
            }
            while (r < i.r) {
                r++;
                add(r);
            }
            while (r > i.r) {
                del(r);
                r--;
            }
            while (l < i.l) {
                del(l);
                l++;
            }
            while (l > i.l) {
                l--;
                add(l);
            }
            ll tt1 = res - (r - l + 1);
            ll tt2 = (ll)(r - l + 1) * (r - l);
            ll g = gcd(tt1, tt2);
            if (tt1 == 0) {
                tt2 = 1;
                ans[i.id].first = tt1, ans[i.id].second = tt2;
                continue;
            }
            tt1 /= g;
            tt2 /= g;
            ans[i.id].first = tt1, ans[i.id].second = tt2;
        }
        for (int i = 1; i <= m; i++) {
            printf("%lld/%lld\n", ans[i].first, ans[i].second);
        }
    }
    return 0;
}