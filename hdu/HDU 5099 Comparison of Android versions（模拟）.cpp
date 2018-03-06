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

vector<string>vs_a, vs_b;
void pretreat() {}
void input() {
    vs_a.clear(), vs_a.resize(3);
    vs_b.clear(), vs_b.resize(3);
    for(int i = 0; i < 6; ++i) {
        char ch = getchar();
        if(i < 2) {
            vs_a[0].push_back(ch);
        } else if(i >= 2 && i < 5) {
            vs_a[1].push_back(ch);
        } else {
            vs_a[2].push_back(ch);
        }
    }
    getchar();
    for(int i = 0; i < 6; ++i) {
        char ch = getchar();
        if(i < 2) {
            vs_b[0].push_back(ch);
        } else if(i >= 2 && i < 5) {
            vs_b[1].push_back(ch);
        } else {
            vs_b[2].push_back(ch);
        }
    }
    getchar();
}

void solve(int cs) {
    string a, b;
    printf("Case %d: ", cs);
    if(vs_a[0][0] > vs_b[0][0]) {
        printf("> ");
    } else if(vs_a[0][0] == vs_b[0][0]) {
        printf("= ");
    } else {
        printf("< ");
    }

    if(vs_a[0][1] != vs_b[0][1]) {
        if(vs_a[1] > vs_b[1]) {
            printf(">\n");
        } else if(vs_a[1] == vs_b[1]) {
            printf("=\n");
        } else {
            printf("<\n");
        }
    } else {
        vs_a[1] += vs_a[2];
        vs_b[1] += vs_b[2];
        if(vs_a[1] > vs_b[1]) {
            printf(">\n");
        } else if(vs_a[1] == vs_b[1]) {
            printf("=\n");
        } else {
            printf("<\n");
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    pretreat();
    int t;
    cin >> t;
    getchar();
    for (int i = 1; i <= t; ++i) {
        input();
        solve(i);
    }
    return 0;
}
