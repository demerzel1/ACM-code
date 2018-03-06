#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
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
            sum+=det(P[i+1],P[i]);
        sum+=det(P[0],P[P.size()-1]);
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
typedef complex<double> Point;
typedef pair<Point,Point> Halfplane;
const double EPS=1e-10;
const double INF=10000;

inline int sgn(double n){
    return fabs(n)<EPS ? 0 : (n<0 ? -1 : 1);
}
inline double cross(Point a,Point b){
    return (conj(a)*b).imag();
}
inline double dot(Point a,Point b){
    return (conj(a)*b).real();
}
inline double satisfy(Point a,Halfplane p){
    return sgn(cross(a-p.first,p.second-p.first))<=0;
}

Point crosspoint(const Halfplane &a,const Halfplane &b){
    double k=cross(b.first-b.second,a.first-b.second);
    k=k/(k-cross(b.first-b.second,a.second-b.second));
    return a.first+(a.second-a.first)*k;
}

bool cmp1(const Halfplane &a,const Halfplane &b){
    int res=sgn(arg(a.second-a.first)-arg(b.second-b.first));
    return res==0 ? satisfy(a.first,b):res<0;
}

vector<Point> halfplaneIntersection(vector<Halfplane> v){
    sort(v.begin(),v.end(),cmp1);
    deque<Halfplane> q;
    deque<Point> ans;
    q.push_back(v[0]);
    for(int i=1;i<int(v.size());i++){
        if(sgn(arg(v[i].second-v[i].first)-arg(v[i-1].second-v[i-1].first))==0)
            continue;
        while(ans.size()>0&&!satisfy(ans.back(),v[i])){
            ans.pop_back();
            q.pop_back();
        }
        while(ans.size()>0&&!satisfy(ans.front(),v[i])){
            ans.pop_front();
            q.pop_front();
        }
        ans.push_back(crosspoint(q.back(),v[i]));
        q.push_back(v[i]);
    }
    while(ans.size()>0&&!satisfy(ans.back(),q.front())){
        ans.pop_back();
        q.pop_back();
    }
    while(ans.size()>0&&!satisfy(ans.front(),q.back())){
        ans.pop_front();
        q.pop_front();
    }
    ans.push_back(crosspoint(q.back(),q.front()));
    return vector<Point>(ans.begin(),ans.end());
}

struct polygon{
    int n;
    point a[maxn];
    polygon(){}
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
            if(calc(L,a.P[j])>-eps){
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
    }
    return res;
}
