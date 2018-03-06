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
#include <climits>
#include <ctime>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include<complex>
#include <algorithm>
using namespace std;

const int maxn=100000;
const double pi=acos(-1.0);
const double eps=1e-8;
//double类型的数，判断符号
int cmp(double x){
    if(fabs(x)<eps) return 0;
    if(x>0) return 1;
    return -1;
}
//二维点类，可进行向量运算
//计算平方
inline double sqr(double x){
    return x*x;
}
struct point{
    double x,y;
    point(){}
    point(double a,double b):x(a),y(b){}
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    friend point operator + (const point &a,const point &b){
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator - (const point &a,const point &b){
        return point(a.x-b.x,a.y-b.y);
    }
    friend bool operator == (const point &a,const point &b){
        return cmp(a.x-b.x)==0&&cmp(a.y-b.y)==0;
    }
    friend point operator * (const point &a,const double &b){
        return point(a.x*b,a.y*b);
    }
    friend point operator * (const double &a,const point &b){
        return point(a*b.x,a*b.y);
    }
    friend point operator / (const point &a,const double &b){
        return point(a.x/b,a.y/b);
    }
    double norm(){
        return sqrt(sqr(x)+sqr(y));
    }
};
//计算向量叉积
double det(const point &a,const point &b){
    return a.x*b.y-a.y*b.x;
}
//计算向量点积
double dot(const point &a,const point &b){
    return a.x*b.x+a.y*b.y;
}
//计算两点距离
double dist(const point &a,const point &b){
    return (a-b).norm();
}
//op绕原点逆时针旋转A弧度
point rotate_point(const point &p,double A){
    double tx=p.x,ty=p.y;
    return point(tx*cos(A)-ty*sin(A),tx*sin(A)+ty*cos(A));
}


struct polygon_convex{
    vector<point> P;
    polygon_convex(int Size=0){
        P.resize(Size);
    }
    double area(){
        double sum=0;
        for(int i=0;i<P.size()-1;i++)
            sum+=det(P[i],P[i+1]);
        sum+=det(P[P.size()-1],P[0]);
        return sum/2.;
    }
};

bool comp_less(const point &a,const point &b){
    return cmp(a.x-b.x)<0||cmp(a.x-b.x)==0&&cmp(a.y-b.y)<0;
}

polygon_convex convex_hull(vector<point> a){
    polygon_convex res(2*a.size()+5);
    sort(a.begin(),a.end(),comp_less);
    a.erase(unique(a.begin(),a.end()),a.end());
    int m=0;
    for(int i=0;i<a.size();i++){
        while(m>1&&cmp(det(res.P[m-1]-res.P[m-2],a[i]-res.P[m-2]))<=0) --m;
        res.P[m++]=a[i];
    }
    int k=m;
    for(int i=int(a.size())-2;i>=0;--i){
        while(m>k&&cmp(det(res.P[m-1]-res.P[m-2],a[i]-res.P[m-2]))<=0) --m;
        res.P[m++]=a[i];
    }
    res.P.resize(m);
    if(a.size()>1)  res.P.resize(m-1);
    return res;
}
const double EPS=1e-10;
const double INF=100000;

struct polygon{
    int n;
    point a[maxn];
    polygon(){}
    double area(){
        double sum=0;
        a[n]=a[0];
        for(int i=0;i<n;i++)
            sum+=det(a[i+1],a[i]);
        return sum/2.;
    }
};

struct halfplane{
    double a,b,c;
    halfplane(point p,point q){
        a=p.y-q.y;
        b=q.x-p.x;
        c=det(p,q);
    }
    halfplane (double aa,double bb,double cc){
        a=aa;
        b=bb;
        c=cc;
    }
};

double calc(halfplane &L,point &a){
    return a.x*L.a+a.y*L.b+L.c;
}

point Intersect(point &a,point &b,halfplane &L){
    point res;
    double t1=calc(L,a),t2=calc(L,b);
    res.x=(t2*a.x-t1*b.x)/(t2-t1);
    res.y=(t2*a.y-t1*b.y)/(t2-t1);
    return res;
}

polygon_convex cut(polygon_convex &a,halfplane &L){
    int n=a.P.size();
    polygon_convex res;
    for(int i=0;i<n;i++){
        if(calc(L,a.P[i])<-eps)
            res.P.push_back(a.P[i]);
        else{
            int j;
            j=i-1;
            if(j<0)
                j=n-1;
            if(calc(L,a.P[j])<-eps){
                res.P.push_back(Intersect(a.P[j],a.P[i],L));
            }
            j=i+1;
            if(j==n)
                j=0;
            if(calc(L,a.P[j])<-eps)
                res.P.push_back(Intersect(a.P[i],a.P[j],L));
        }
    }
    return res;
}

polygon_convex core(polygon &a){
    polygon_convex res;
    res.P.push_back(point(-INF,-INF));
    res.P.push_back(point(INF,-INF));
    res.P.push_back(point(INF,INF));
    res.P.push_back(point(-INF,INF));
    int n=a.n;
    for(int i=0;i<n;i++){
        halfplane L(a.a[i],a.a[(i+1)%n]);
        res=cut(res,L);
       // cout<<i<<"\n";
    }
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        polygon pg;
        pg.n=n;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&pg.a[i].x,&pg.a[i].y);
        }
        polygon_convex pc=core(pg);
      //  cout<<pc.P.size()<<"\n";
        if(pc.P.size()==0)
            printf("0.00\n");
        else
            printf("%.2f\n",pc.area());
    }
    return 0;
}
