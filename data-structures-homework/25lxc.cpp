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
    int x, y;
    Point(int x = 0, int y = 0): x(x), y(y) {}
    void in() {
        scanf(" %d %d", &x, &y);
    }
    int dist(Point p) {
        double ans =  sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
        return ceil(ans);
    }
};
int dist[SZ][SZ];
int g_n, g_q;
vector<int>vi_r;
vector<Point>vp_in;
vector<vector<int>>vvi_dist;

void pretreat() {}
bool input() {
    scanf(" %d %d", &g_n, &g_q);
    if(g_n == 0 && g_q == 0)
        return false;
    memset(dist, 0, sizeof(dist));
    vi_r.clear(), vp_in.clear(), vp_in.resize(g_n);
    vvi_dist.clear(), vvi_dist.resize(g_n);
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
            dist[i][j] = dist[j][i] = vp_in[i].dist(vp_in[j]);
        }
    }
    for(int i = 0; i < g_n; ++i) {
        for(int j = 0; j < g_n; ++j) {
            vvi_dist[i].push_back(dist[i][j]);
        }
    }
    for(int i = 0; i < g_n; ++i) {
        sort(vvi_dist[i].begin(), vvi_dist[i].end());
    }
    for(int i = 0; i < g_q; ++i) {
        int r = vi_r[i];
        int sum = 0;
        for(vector<int> &vit : vvi_dist) {
            int cnt = upper_bound(vit.begin(), vit.end(), r) - vit.begin();
            sum += cnt;
        }
        //cout << r << "->" << sum << endl;
        printf("%.2f\n", (double)sum / g_n);
    }
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
