#pragma warning (disable:4996)
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
#include <set>
#include <ctime>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const double EPS = 1e-9;
const double PI = 2 * asin(1);
const int INF = 0x7fffffff;
const LL LINF = 0x7fffffffffffffff;
const int SZ = 3000 + 10;

struct Point {
    LL x, y;
    Point(LL x = 0, LL y = 0): x(x), y(y) {}
    void in() {
        scanf(" %lld %lld", &x, &y);
    }
    LL dist(Point p) {
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
    }
};
int dist[SZ][SZ];
int g_n, g_q;
vector<int>vi_r;
vector<Point>vp_in;
vector<LL>vll_dist;

void pretreat() {}
bool input() {
    scanf(" %d %d", &g_n, &g_q);
    if(g_n == 0 && g_q == 0)
        return false;
    memset(dist, 0, sizeof(dist));
    vi_r.clear(), vp_in.clear(), vp_in.resize(g_n);
    vll_dist.clear();
    for(int i = 0; i < g_n; ++i) {
        vp_in[i].in();
    }
    for(int i = 0, t; i < g_q; ++i) {
        scanf(" %d", &t);
        vi_r.push_back(t);
    }
    return true;
}

void solve() {
    for(int i = 0; i < g_n; ++i) {
        for(int j = i + 1; j < g_n; ++j) {
            vll_dist.push_back(vp_in[i].dist(vp_in[j]));
        }
    }
    sort(vll_dist.begin(), vll_dist.end());
    for(int i = 0; i < g_q; ++i) {
        LL r = vi_r[i];
        LL sum = upper_bound(vll_dist.begin(), vll_dist.end(), r * r) - vll_dist.begin();
        sum = 2 * sum + g_n;
        //cout << r << "->" << sum << endl;
        printf("%.2f\n", (double)sum / g_n);
    }
    puts("");
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    pretreat();
    while (input()) {
        solve();
    }
    return 0;
}
