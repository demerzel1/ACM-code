#include<bits/stdc++.h>
using namespace std;

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


//线段类
struct line{
    point a,b;
    line(){}
    line(point x,point y):a(x),b(y){}
};
//用两个点a，b生成的线段或直线
line point_make_line(const point a,const point b){
    return line(a,b);
}
//求p到线段st的距离
double dis_point_segment(const point p,const point s,const point t){
    if(cmp(dot(p-s,t-s))<0) return (p-s).norm();
    if(cmp(dot(p-t,s-t))<0) return (p-t).norm();
    return fabs(det(s-p,t-p)/dist(s,t));
}
//求p到线段st的垂足，保存在cp中
void PointProjLine(const point p,const point s,const point t,point &cp){
    double r=dot((t-s),(p-s))/dot(t-s,t-s);
    cp=s+r*(t-s);
}
//判断p是否在线段st上（包括端点）
bool PointOnSegment(point p,point s,point t){
    return cmp(det(p-s,t-s))==0 && cmp(dot(p-s,p-t))<=0;
}
//判断a，b是否平行
bool parallel(line a,line b){
    return !cmp(det(a.a-a.b,b.a-b.b));
}
//判断a，b是否相交，如果相交则返回true且交点保存在res中
bool line_make_point(line a,line b,point &res){
    if(parallel(a,b)) return false;
    double s1=det(a.a-b.a,b.b-b.a);
    double s2=det(a.b-b.a,b.b-b.a);
    res=(s1*a.b-s2*a.a)/(s1-s2);
    return true;
}
//将直线a沿法向量平移距离len得到的直线
line move_d(line a,const double &len){
    point d=a.b-a.a;
    d=d/d.norm();
    d=rotate_point(d,pi/2);
    return line(a.a+d*len,a.b+d*len);
}

point p1,p2;
double r;

int main(){
 //   freopen("in.txt", "r", stdin);
  //  freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        cin>>p1.x>>p1.y>>p2.x>>p2.y>>r;
        if(p1.x==p2.x&&p1.y==p2.y){
            cout<<setiosflags(ios::fixed)<<setprecision(3)<<0.000<<"\n";
            continue;
        }

        if(dis_point_segment(point(0,0),p1,p2)>=r){
          //  cout<<111<<"\n";
            cout<<setiosflags(ios::fixed)<<setprecision(3)<<dist(p1,p2)<<"\n";
        }else{
            double a=dist(p1,point(0,0));
            double b=dist(p2,point(0,0));
            double c=dist(p1,p2);
    //        cout<<a<<" "<<b<<" "<<c<<"\n";
            double d1=acos(r/a);
            double d2=acos(r/b);
            double d3=acos((a*a+b*b-c*c)/(2*a*b));
            double d=d3-d1-d2;
            double l=d*r;
            double l1=a*sin(d1);
            double l2=b*sin(d2);
            cout<<setiosflags(ios::fixed)<<setprecision(3)<<l1+l2+l<<"\n";
        }
    }
    return 0;
}
