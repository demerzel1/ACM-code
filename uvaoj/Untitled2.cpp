#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
const double esp = 1e-9;
using namespace std;
struct Point {
    double x, y;
    Point() {}
    Point(double xx, double yy) {
        x = xx; y = yy;
    }
} p[10];

struct Line {
    Point a, b;
    double A, B, C;
    Line() {}
    Line(Point aa, Point bb) {
        a = aa; b = bb;
        A = b.y - a.y;
        B = a.x - b.x;
        C = (A * a.x + B * a.y);
    }
} l[15], save[15];

inline bool px(Line a, Line b) {
    if (fabs((a.b.y - a.a.y) * (b.b.x - b.a.x) - (b.b.y - b.a.y) * (a.b.x - a.a.x)) < esp) return true;
    return false;
}

inline Point jd(Line a, Line b) {
    Point pp((b.B * a.C - a.B * b.C) / (a.A * b.B - b.A * a.B) ,(a.A * b.C - b.A * a.C) / (a.A * b.B - b.A * a.B));
    return pp;
}

int t, P, ln, sn, i, ord[10];
double n, m;

inline double dis(Point a, Point b) {
    return sqrt((b.y - a.y) * (b.y - a.y) + (b.x - a.x) * (b.x - a.x));
}

inline bool outside(Point a, Point b, Point c) {
    return (c.x - a.x) * (b.x - a.x) + (c.y - a.y) * (b.y - a.y) > esp;
}

inline double find(Line li) {
    double mina = 2000000000, minb = 2000000000;
    Point aa, bb;
    for (int i = 0; i < sn; i++) {
        if (px(li, save[i])) continue;
        Point c = jd(li, save[i]);
        double disa = dis(li.a ,c), disb = dis(li.b , c);
        if (outside(li.b, li.a, c) && disa - mina < esp) {
            mina = disa;
            aa = c;
        }
        if (outside(li.a, li.b, c) && disb - minb < esp) {
            minb = disb;
            bb = c;
        }
    }
    return dis(aa, bb);
}

inline double cal() {
    double sum = 0;
    sn = 4;
    for (int i = 0; i < P; i++) {
        sum += find(l[ord[i]]);
        save[sn++] = l[ord[i]];
    }
    return sum;
}

inline double solve() {
    double ans = 2000000000;
    save[sn++] = Line(Point(0, 0), Point(0, m));
    save[sn++] = Line(Point(0, 0), Point(n, 0));
    save[sn++] = Line(Point(n, 0), Point(n, m));
    save[sn++] = Line(Point(0, m), Point(n, m));
    do {
        double t = cal();
        ans = min(ans, t);
    } while (next_permutation(ord, ord + P));
    return ans;
}

int main() {
    while (~scanf("%lf%lf", &n, &m)) {
        ln = 0, sn = 0;
        scanf("%d", &P);
        for (i = 0; i < P; i++) {
            ord[i] = i;
            scanf("%lf%lf", &p[i].x, &p[i].y);
            if (i != 0)
                l[ln++] = Line(Point(p[i - 1].x, p[i - 1].y), Point(p[i].x, p[i].y));
        }
        l[ln++] = Line(Point(p[P - 1].x, p[P - 1].y), Point(p[0].x, p[0].y));
        printf("Minimum total length = %.3f\n", solve());
        if (t) printf("\n");
    }
    return 0;
}
