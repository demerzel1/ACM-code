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

int g_n, g_k;
vector<vector<int>>vvi_in;

void pretreat() {}
bool input() {
    scanf(" %d %d", &g_n, &g_k);
    vvi_in.clear(), vvi_in.resize(g_k + 1);
    for(int i = 0, t, mod; i < g_n; ++i) {
        scanf(" %d", &t);
        mod = t % g_k;
        if(mod == 0) {
            mod = g_k;
        }
        vvi_in[mod].push_back(t / g_k);
    }
    return true;
}

void solve(int sz) {
    for(int i = 1; i <= g_k; ++i) {
        sort(vvi_in[i].begin(), vvi_in[i].end());
    }
    int n = g_n / g_k, mod = g_n % g_k;
    for(int i = 1; i < g_k; ++i) {
        if(i <= mod) {
            if(vvi_in[i].size() != n + 1) {
                puts("Tom");
                return;
            }
            for(int j = 0; j < n + 1; ++j) {
                if(vvi_in[i][j] > j) {
                    puts("Tom");
                    return;
                }
            }
        } else {
            if(vvi_in[i].size() != n) {
                puts("Tom");
                return;
            }
            for(int j = 0; j < n; ++j) {
                if(vvi_in[i][j] > j) {
                    puts("Tom");
                    return;
                }
            }
        }
    }
    if(vvi_in[g_k].size() != n) {
        puts("Tom");
        return;
    }
    for(int j = 0; j < n; ++j) {
        if(vvi_in[g_k][j] > j + 1) {
            puts("Tom");
            return;
        }
    }
    puts("Jerry");
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
