#include <stdio.h>
#include <math.h>
#include<algorithm>
using namespace std;
const int maxn = 1505;
const double eps = 1e-8;
int n, pn, dq[maxn], top, bot;//数组模拟双端队列
struct Point      //顶点
{
    double x, y;
} p[maxn];

struct Line      //线
{
    Point a, b;
    double angle;//极角
    Line& operator= (Line l)
    {
        a.x = l.a.x;
        a.y = l.a.y;
        b.x = l.b.x;
        b.y = l.b.y;
        angle = l.angle;
        return *this;
    }
} l[maxn];
int dblcmp(double k)//精度函数
{
    if (fabs(k) < eps) return 0;
    return k > 0 ? 1 : -1;
}
double multi(Point p0, Point p1, Point p2)
{                   //叉积
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
bool cmp(const Line& l1, const Line& l2)
{
    int d = dblcmp(l1.angle-l2.angle);
    if (!d)
    return dblcmp(multi(l1.a, l2.a, l2.b)) < 0;
                //大于0取半平面的左半，小于0取右半
    return d < 0;
}
void addLine(Line& l, double x1, double y1, double x2, double y2)
{
    l.a.x = x1;
    l.a.y = y1;
    l.b.x = x2;
    l.b.y = y2;
    l.angle = atan2(y2-y1, x2-x1);
}

void getIntersect(Line l1, Line l2, Point& p)
{
    double A1 = l1.b.y - l1.a.y;
    double B1 = l1.a.x - l1.b.x;
    double C1 = (l1.b.x - l1.a.x) * l1.a.y - (l1.b.y - l1.a.y) * l1.a.x;
    double A2 = l2.b.y - l2.a.y;
    double B2 = l2.a.x - l2.b.x;
    double C2 = (l2.b.x - l2.a.x) * l2.a.y - (l2.b.y - l2.a.y) * l2.a.x;
    p.x = (C2 * B1 - C1 * B2) / (A1 * B2 - A2 * B1);
    p.y = (C1 * A2 - C2 * A1) / (A1 * B2 - A2 * B1);
}

bool judge(Line l0, Line l1, Line l2)
{
    Point p;
    getIntersect(l1, l2, p);
    return dblcmp(multi(p, l0.a, l0.b)) > 0;
    //与上面的注释处的大于小于符号相反，大于0，是p在向量l0.a->l0.b的左边，小于0是在右边，当p不在半平面l0内时，返回true
}

void HalfPlaneIntersect( )
{
    int i, j;
    sort(l, l+n, cmp); //极角排序
    for (i = 0, j = 0; i < n; i++)
        if (dblcmp(l[i].angle-l[j].angle) > 0)
            l[++j] = l[i];//排除极角相同（从了l[1]开始比较）
    n = j + 1;//个数
    dq[0] = 0;//双端队列
    dq[1] = 1;//开始入队列两条直线
    top = 1;
    bot = 0;
    for (i = 2; i < n; i++)
    {
        while (top > bot && judge(l[i], l[dq[top]], l[dq[top-1]])) top--;
        while (top > bot && judge(l[i], l[dq[bot]], l[dq[bot+1]])) bot++;
        dq[++top] = i;
    }
    while (top > bot && judge(l[dq[bot]], l[dq[top]], l[dq[top-1]])) top--;
    while (top > bot && judge(l[dq[top]], l[dq[bot]], l[dq[bot+1]])) bot++;
    dq[++top] = dq[bot];
    for (pn = 0, i = bot; i < top; i++, pn++)
        getIntersect(l[dq[i+1]], l[dq[i]], p[pn]);//更新重复利用p数组
}

double getArea()
{
    if (pn < 3) return 0;
    double area = 0;
    for (int i = 1; i < pn-1; i++)
        area += multi(p[0], p[i], p[i+1]);//利用p数组求面积
    if (area < 0) area = -area;
    return area/2;
}

int main()
{
    int t, i;

    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d", &n);
        for (i = 0; i < n; i++)
            scanf ("%lf%lf", &p[i].x, &p[i].y);
        for (i = 0; i < n-1; i++)
            addLine(l[i], p[i].x, p[i].y, p[i+1].x, p[i+1].y);
        addLine(l[i], p[i].x, p[i].y, p[0].x, p[0].y);
        HalfPlaneIntersect();
        printf ("%.2lf\n", getArea());
    }
    return 0;
}
