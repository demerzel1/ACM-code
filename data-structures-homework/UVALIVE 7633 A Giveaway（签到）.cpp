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
const int num[] = {1, 64, 729, 4096, 15625, 46656, 117649, 262144,
                   531441, 1000000, 1771561, 2985984, 4826809, 7529536,
                   11390625, 16777216, 24137569, 34012224, 47045881, 64000000, 85766121
                  };
int g_n;
set<int>sti_num;

void pretreat() {
    sti_num.clear();
    for(int i = 0; i < 21; ++i) {
        sti_num.insert(num[i]);
    }
}
bool input() {
    if (scanf(" %d", &g_n) == EOF || g_n == 0)
        return false;
    return true;
}

void solve() {
    if(sti_num.find(g_n) != sti_num.end()) {
        puts("Special");
    } else {
        puts("Ordinary");
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
