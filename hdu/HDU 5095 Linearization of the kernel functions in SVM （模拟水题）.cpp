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
const char CHAR[] = {'p', 'q', 'r', 'u', 'v', 'w', 'x', 'y', 'z'};

int num[10];

void pretreat() {}
bool input() {
    for(int i = 0; i < 10; ++i) {
        scanf(" %d", num + i);
    }
    return true;
}


void solve() {
    bool f = true;
    for(int i = 0; i < 10; ++i) {
        if(f) {
            if(i < 9) {
                if(num[i] > 1) {
                    printf("%d%c", num[i], CHAR[i]);
                    f = false;
                } else if(num[i] == 1) {
                    printf("%c",  CHAR[i]);
                    f = false;
                } else if(num[i] == -1) {
                    printf("-%c",  CHAR[i]);
                    f = false;
                } else if(num[i] < -1) {
                    printf("%d%c", num[i], CHAR[i]);
                    f = false;
                }
            } else {
                if(num[i] > 0) {
                    printf("%d", num[i]);
                    f = false;
                } else if(num[i] < 0) {
                    printf("%d", num[i]);
                }
            }
        } else {
            if(i < 9) {
                if(num[i] > 1) {
                    printf("+%d%c", num[i], CHAR[i]);
                } else if(num[i] == 1) {
                    printf("+%c",  CHAR[i]);
                } else if(num[i] == -1) {
                    printf("-%c",  CHAR[i]);
                } else if(num[i] < -1) {
                    printf("%d%c", num[i], CHAR[i]);
                }
            } else {
                if(num[i] > 0) {
                    printf("+%d", num[i]);
                    f = false;
                } else if(num[i] < 0) {
                    printf("%d", num[i]);
                }
            }
        }
    }
    printf("\n");
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    pretreat();
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        input();
        solve();
    }
    return 0;
}
