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
const int SZ  = 1000 + 10;

int g_n;
map<string, int>msi;
vector<bool>vb_re, vb_mark;
vector<int>vi_in;
vector<vector<int>>vvi_e;

void pretreat() {}
void input() {
    msi.clear();
    vb_re.clear(), vb_re.resize(SZ);
    vb_mark.clear(), vb_mark.resize(SZ);
    vi_in.clear(), vi_in.resize(SZ);
    vvi_e.clear(), vvi_e.resize(SZ);

    g_n = 0;
    int u, v;
    string str;
    while(true) {
        getline(cin, str);
        if(str.empty()) {
            return;
        }
        bool f;
        int sz = 0;
        stringstream ss(str);
        while(ss >> str) {
            if(sz == 0) {
                str.pop_back();
                if(str.back() == '*') {
                    f = true;
                    str.pop_back();
                } else {
                    f = false;
                }
                if(msi.find(str) == msi.end()) {
                    msi[str] = ++g_n;
                }
                u = msi[str];
                vb_re[u] = f;
            } else {
                v = msi[str];
                vvi_e[v].push_back(u);
                ++vi_in[u];
            }
            ++sz;
        }
    }
}

void solve(int sz) {
    queue<int>qi1, qi2;
    for(int i = 1; i <= g_n; ++i) {
        if(vi_in[i] != 0)continue;
        if(vb_re[i]) {
            qi2.push(i);
        } else {
            qi1.push(i);
        }
    }
    int cnt = 0;
    while(!qi1.empty() || !qi2.empty()) {
        if(qi1.empty() && !qi2.empty()) {
            ++cnt;
            while(!qi2.empty()) {
                qi1.push(qi2.front());
                qi2.pop();
            }
        }
        while(!qi1.empty()) {
            int u = qi1.front();
            qi1.pop();
            vb_mark[u] = true;
            for(int i = 0; i < vvi_e[u].size(); ++i) {
                int v = vvi_e[u][i];
                --vi_in[v];
                if(vi_in[v] == 0) {
                    if(vb_re[v]) {
                        qi2.push(v);
                    } else {
                        qi1.push(v);
                    }
                }
            }
        }
    }
    printf("Case %d: %d\n", sz, cnt);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    pretreat();
    int t;
    cin >> t;
    getchar();
    getchar();
    for (int i = 1; i <= t; ++i) {
        input();
        solve(i);
    }
    return 0;
}
