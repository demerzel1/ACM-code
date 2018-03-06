#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn = 200005;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-9;

template<class T>
inline void read (T &x) {
    int c;
    for (c = getchar(); c < 32 && ~c; c = getchar());
    for (x = 0; c > 32; x = x * 10 + c - '0', c = getchar());
}

int is_leap (int year) {

    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 1;
    else
        return 0;
}

int ReturnWeekDay (unsigned int iYear, unsigned int iMonth, unsigned int iDay) {
    int iWeek = 0;
    unsigned int y = 0, c = 0, m = 0, d = 0;

    if (iMonth == 1 || iMonth == 2) {
        c = (iYear - 1) / 100;
        y = (iYear - 1) % 100;
        m = iMonth + 12;
        d = iDay;
    } else {
        c = iYear / 100;
        y = iYear % 100;
        m = iMonth;
        d = iDay;
    }

    iWeek = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;    //蔡勒公式
    iWeek = iWeek >= 0 ? (iWeek % 7) : (iWeek % 7 + 7);    //iWeek为负时取模
    if (iWeek == 0)    //星期日不作为一周的第一天
    {
        iWeek = 7;
    }

    return iWeek;
}

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, c;
        char c2, c1;
        scanf("%d%c%d%c%d", &a, &c2, &b, &c1, &c);
        int t = ReturnWeekDay(a, b, c);
        if (is_leap(a) && b == 2 && c == 29) {
            while (true) {
                a += 4;
                if (!is_leap(a))
                    continue;
                if (t == ReturnWeekDay(a, b, c)) {
                    printf("%d\n", a);
                    break;
                }
            }
        } else {
            while (true) {
                a++;
                if (t == ReturnWeekDay(a, b, c)) {
                    printf("%d\n", a);
                    break;
                }
            }
        }
    }
    return 0;
}