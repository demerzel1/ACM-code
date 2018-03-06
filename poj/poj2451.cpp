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
#include <complex>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
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

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        vector<Halfplane> v;
        Point t1(0,0),t2(10000,0),t3(10000,10000),t4(0,10000);
        v.push_back(make_pair(t1,t2));
        v.push_back(make_pair(t2,t3));
        v.push_back(make_pair(t3,t4));
        v.push_back(make_pair(t4,t1));
        double a,b,c,d;
        for(int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
            v.push_back(make_pair(Point(a,b),Point(c,d)));
        }
        vector<Point> ans=halfplaneIntersection(v);
       // cout<<ans.size();
        double sum=0;
        for(int i=0;i<ans.size()-1;i++)
            sum+=cross(ans[i],ans[i+1]);
        sum+=cross(ans[ans.size()-1],ans[0]);
        sum=sum/2.;
        printf("%.1f\n",sum);
    }
    return 0;
}
