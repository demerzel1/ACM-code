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
const int SZ = 50 + 10;

int g_p, g_q, g_xn, g_yn;
vector<string>vs;
vector<bool>vb_mark;
vector<int>vi_match;
vector<vector<bool> >vvb_edge;
vector<vector<int> >vvi_x, vvi_y;

void pretreat() {}
void input() {
    scanf(" %d %d", &g_xn, &g_yn);

    vi_match.clear(),vb_mark.clear(),vs.clear();
    vvb_edge.clear(), vvi_x.clear(), vvi_y.clear();
    vvi_x.resize(g_xn), vvi_y.resize(g_xn);
    for (int i = 0; i < g_xn; ++i) {
        vvi_x[i].resize(g_yn);
        vvi_y[i].resize(g_yn);
    }
    char s[SZ];
    for (int i = 0; i < g_xn; ++i) {
        scanf(" %s", s);
        vs.push_back(string(s));
    }
}
bool dfs(int u) {
    for (int i = 1; i < g_q; ++i) {
        if (!vb_mark[i] && vvb_edge[u][i]) {
            vb_mark[i] = true;
            if (vi_match[i] == 0 || dfs(vi_match[i])) {
                vi_match[i] = u;
                return true;
            }
        }
    }
    return false;
}
void solve(int sz) {
    g_p = 1;
    for (int i = 0; i < g_xn; ++i) {
        bool f = false;
        for (int j = 0; j < g_yn; ++j) {
            if (vs[i][j] == '*') {
                vvi_x[i][j] = g_p;
                f = true;
            } else if (vs[i][j] == '#') {
                ++g_p;
                f = false;
            }
        }
        if (f) {
            ++g_p;
        }
    }

    g_q = 1;
    for (int j = 0; j < g_xn; ++j) {
        bool f = false;
        for (int i = 0; i < g_yn; ++i) {
            if (vs[i][j] == '*') {
                vvi_y[i][j] = g_q;
                f = true;
            } else if (vs[i][j] == '#') {
                ++g_q;
                f = false;
            }
        }
        if (f) {
            ++g_q;
        }
    }
    vvb_edge.resize(g_p);
    for (int i = 0; i < g_p; ++i) {
        vvb_edge[i].resize(g_q);
    }
    for (int i = 0; i < g_xn; ++i) {
        for (int j = 0; j < g_yn; ++j) {
            if (vs[i][j]=='*') {
                vvb_edge[vvi_x[i][j]][vvi_y[i][j]] = true;
            }
        }
    }
    int cnt = 0;
    vb_mark.resize(g_p);
    vi_match.resize(g_p);
    for (int i = 1; i < g_p; ++i) {
        fill(vb_mark.begin(), vb_mark.end(), false);
        if (dfs(i))
            ++cnt;
    }
    printf("%d\n", cnt);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    pretreat();
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        input();
        solve(i);
    }
    return 0;
}
