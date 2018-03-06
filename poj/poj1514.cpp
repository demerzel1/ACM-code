#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include<iomanip>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include<complex>
#include <algorithm>
using namespace std;

const int maxn=105;
const double pi=acos(-1.0);
const double eps=1e-8;
//double类型的数，判断符号
int cmp(double x) {
    if(fabs(x)<eps) return 0;
    if(x>0) return 1;
    return -1;
}
//二维点类，可进行向量运算
//计算平方
inline double sqr(double x) {
    return x*x;
}
struct point {
    double x,y;
    point() {}
    point(double a,double b):x(a),y(b) {}
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    friend point operator + (const point &a,const point &b) {
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator - (const point &a,const point &b) {
        return point(a.x-b.x,a.y-b.y);
    }
    friend bool operator == (const point &a,const point &b) {
        return cmp(a.x-b.x)==0&&cmp(a.y-b.y)==0;
    }
    friend point operator * (const point &a,const double &b) {
        return point(a.x*b,a.y*b);
    }
    friend point operator * (const double &a,const point &b) {
        return point(a*b.x,a*b.y);
    }
    friend point operator / (const point &a,const double &b) {
        return point(a.x/b,a.y/b);
    }
    double norm() {
        return sqrt(sqr(x)+sqr(y));
    }
};
//计算向量叉积
double det(const point &a,const point &b) {
    return a.x*b.y-a.y*b.x;
}
//计算向量点积
double dot(const point &a,const point &b) {
    return a.x*b.x+a.y*b.y;
}
//计算两点距离
double dist(const point &a,const point &b) {
    return (a-b).norm();
}



struct polygon_convex {
    vector<point> P;
    polygon_convex(int Size=0) {
        P.resize(Size);
    }
    double area() {
        double sum=0;
        for(int i=0; i<P.size()-1; i++)
            sum+=det(P[i],P[i+1]);
        sum+=det(P[P.size()-1],P[0]);
        return sum/2.;
    }
};

struct halfplane {
    double a,b,c;
    halfplane(point p,point q) {
        a=p.y-q.y;
        b=q.x-p.x;
        c=det(p,q);
    }
    halfplane() {}
    halfplane(double aa,double bb,double cc) {
        a=aa;
        b=bb;
        c=cc;
    }
};

double calc(halfplane &L,point &a) {
    return a.x*L.a+a.y*L.b+L.c;
}

point Intersect(point &a,point &b,halfplane &L) {
    point res;
    double t1=calc(L,a),t2=calc(L,b);
    res.x=(t2*a.x-t1*b.x)/(t2-t1);
    res.y=(t2*a.y-t1*b.y)/(t2-t1);
    return res;
}

double tans,ans;

polygon_convex cut(polygon_convex &a,halfplane &L) {
    int n=a.P.size();
    point A;
    point B;
    A=B=point(0,0);
    polygon_convex res;
//    int cnt=0;
//    bool flag=false;
    for(int i=0; i<n; i++) {
        if(calc(L,a.P[i])<-eps)
            res.P.push_back(a.P[i]);
        else {
//            if(flag)
//                continue;
            int j;
            j=i-1;
            if(j<0)
                j=n-1;
            if(calc(L,a.P[j])<-eps) {
                B=A;
                A=Intersect(a.P[j],a.P[i],L);
                res.P.push_back(A);
//                cnt++;
//                if(cnt==2)
//                    flag=true;
            }
            j=i+1;
            if(j==n)
                j=0;
            if(calc(L,a.P[j])<-eps) {
                B=A;
                A=Intersect(a.P[i],a.P[j],L);
                res.P.push_back(A);
//                cnt++;
//                if(cnt==2)
//                    flag=true;
            }
        }
    }
    // cout<<dist(A,B)<<"\n";
    tans+=dist(A,B);
    return res;
}

point ver[10];
int num[10];
int n,m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n) {
        cin>>m;
        int p;
        //cin>>p;
        scanf("%d",&p);
        for(int i=0; i<p; i++) {
            cin>>ver[i].x>>ver[i].y;
             scanf("%lf%lf",&ver[i].x,&ver[i].y);
            num[i]=i;
        }
        ans=1e20;
        halfplane L[10];
        for(int i=0; i<p; i++) {
            L[i]=halfplane(ver[i],ver[(i+1)%p]);
        }
        polygon_convex pc;
        do {
            tans=0;
            pc.P.clear();
            pc.P.push_back(point(0,0));
            pc.P.push_back(point((double)n,0));
            pc.P.push_back(point((double)n,(double)m));
            pc.P.push_back(point(0,(double)m));
            for(int i=0; i<p; i++) {
                pc=cut(pc,L[num[i]]);
            }
            //  cout<<ans<<"  ans\n";
            ans=min(ans,tans);
        } while(next_permutation(num,num+p));
        cout<<"Minimum total length = "<<fixed<<setprecision(3)<<ans<<"\n";
        //printf("Minimum total length = %.3f\n",ans);
    }
    return 0;
}
