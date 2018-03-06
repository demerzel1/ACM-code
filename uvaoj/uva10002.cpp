#include<bits/stdc++.h>
using namespace std;

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
//op绕原点逆时针旋转A弧度
point rotate_point(const point &p,double A) {
    double tx=p.x,ty=p.y;
    return point(tx*cos(A)-ty*sin(A),tx*sin(A)+ty*cos(A));
}

const int maxn=105;

struct polygon {
    int n;
    point a[maxn];
    polygon() {}
    double area() {
        double sum=0;
        a[n]=a[0];
        for(int i=0; i<n; i++)
            sum+=det(a[i+1],a[i]);
        //    cout<<"sum="<<sum/2.0<<"\n";
        return sum/2.0;
    }
    point MassCenter() {
        point ans=point(0,0);
        if(cmp(area())==0)
            return ans;
        //   cout<<11111<<"\n";
        a[n]=a[0];
        for(int i=0; i<n; i++)
            ans=ans+(a[i]+a[i+1])*det(a[i+1],a[i]);
        return ans/area()/6.;
    }
};



struct polygon_convex {
    vector<point> P;
    polygon_convex(int Size=0) {
        P.resize(Size);
    }
};

bool comp_less(const point &a,const point &b) {
    return cmp(a.x-b.x)<0||cmp(a.x-b.x)==0&&cmp(a.y-b.y)<0;
}

polygon_convex convex_hull(vector<point> a) {
    polygon_convex res(2*a.size()+5);
    sort(a.begin(),a.end(),comp_less);
    a.erase(unique(a.begin(),a.end()),a.end());
    int m=0;
    for(int i=0; i<a.size(); i++) {
        while(m>1&&cmp(det(res.P[m-1]-res.P[m-2],a[i]-res.P[m-2]))<=0) --m;
        res.P[m++]=a[i];
    }
    int k=m;
    for(int i=int(a.size())-2; i>=0; --i) {
        while(m>k&&cmp(det(res.P[m-1]-res.P[m-2],a[i]-res.P[m-2]))<=0) --m;
        res.P[m++]=a[i];
    }
    res.P.resize(m);
    if(a.size()>1)  res.P.resize(m-1);
    return res;
}


int main() {
    int n;
    while(cin>>n&&(n>=3)) {
        polygon p;
        polygon_convex pc;
        vector<point> v;
        int x,y;
        for(int i=0; i<n; i++) {
            cin>>x>>y;
            v.push_back(point(x,y));
        }
        pc=convex_hull(v);
        for(int i=0; i<pc.P.size(); i++) {
            p.a[i]=pc.P[i];
            //    cout<<p.a[i].x<<" "<<p.a[i].y<<"\n";
        }
        p.n=pc.P.size();
        point ans=p.MassCenter();
        if(cmp(ans.x))
            printf("%.3f ", ans.x);
        else
            printf("0.000 ");
        if(cmp(ans.y))
            printf("%.3f\n", ans.y);
        else
            printf("0.000\n");
    }
    return 0;
}

