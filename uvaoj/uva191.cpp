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
point res;
//判断a，b是否相交，如果相交则返回true且交点保存在res中
bool line_make_point(line a,line b){
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
point q1,q2,ql,qr;

////////////////////////////////////////////////////

bool judge(line a,line b){
    if(line_make_point(a,b)){
        if(PointOnSegment(res,a.a,a.b)&&PointOnSegment(res,b.a,b.b))
            return true;
        else
            return false;
    }else
        return false;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&q1.x,&q1.y,&q2.x,&q2.y,&ql.x,&ql.y,&qr.x,&qr.y);
        if(ql.x>qr.x)
            swap(ql.x,qr.x);
        if(ql.y<qr.y)
            swap(ql.y,qr.y);
        if(q1.x>=ql.x&&q1.x<=qr.x&&q1.y<=ql.y&&q1.y>=qr.y&&q2.x>=ql.x&&q2.x<=qr.x&&q2.y<=ql.y&&q2.y>=qr.y){
            printf("T\n");
        }else{
            line l=line(q1,q2);
            line l1=line(ql,point(ql.x,qr.y));
            line l2=line(ql,point(qr.x,ql.y));
            line l3=line(point(qr.x,ql.y),qr);
            line l4=line(point(ql.x,qr.y),qr);
            if(judge(l,l1)||judge(l,l2)||judge(l,l3)||judge(l,l4))
                printf("T\n");
            else
                printf("F\n");
        }
    }
    return 0;
}
