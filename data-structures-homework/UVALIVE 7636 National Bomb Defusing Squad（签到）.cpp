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

int g_num, g_q, g_cnt;
map<char, int>mci;

void pretreat() {
    mci.clear();
    for(int i = 0; i < 10; ++i) {
        mci['0' + i] = i;
    }
    for(int i = 0; i < 6; ++i) {
        mci['A' + i] = 10 + i;
    }
}

int get_10bit(string s) {
    int cnt = 0;
    if(s[cnt] == '0') {
        ++cnt;
        if(s[cnt] == 'x') {
            ++cnt;
            int ans = 0;
            for(int i = cnt; i < s.size(); ++i) {
                ans *= 16;
                ans += mci[s[i]];
            }
            return ans;
        } else {
            int ans = 0;
            for(int i = cnt; i < s.size(); ++i) {
                ans *= 8;
                ans += mci[s[i]];
            }
            return ans;
        }
    } else {
        int ans = 0;
        for(int i = cnt; i < s.size(); ++i) {
            ans *= 10;
            ans += mci[s[i]];
        }
        return ans;
    }
}
bool input() {
    char ch[12];
    scanf(" %s %d", ch, &g_q);
    string str(ch);
    if(str == "0" && g_q == 0)
        return false;
    g_num = get_10bit(str);
    // cout << g_num << endl;
    return true;
}
void get_num(string s, int &num, int check) {
    if(s == "++i") {
        ++num;
        if(num == check) {
            ++g_cnt;
        } else {
            num = check;
        }
    } else if(s == "i++") {
        if(num == check) {
            ++g_cnt;
        }
        num = check;
        ++num;
    } else if(s == "--i") {
        --num;
        if(num == check) {
            ++g_cnt;
        } else {
            num = check;
        }
    } else if(s == "i--") {
        if(num == check) {
            ++g_cnt;
        }
        num = check;
        --num;
    } else if(s == "i") {
        if(num == check) {
            ++g_cnt;
        } else {
            num = check;
        }
    }
}

void solve() {
    g_cnt = 0;
    int num = g_num, nin;
    char ch[9];
    while(g_q--) {
        scanf(" %s %d", ch, &nin);
        string str(ch);
        get_num(str, num, nin);
    }
    printf("%d\n", g_cnt);
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
