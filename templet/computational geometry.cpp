#include<bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);
const double eps=1e-8;
//double���͵������жϷ���
int cmp(double x){
    if(fabs(x)<eps) return 0;
    if(x>0) return 1;
    return -1;
}
//��ά���࣬�ɽ�����������
//����ƽ��
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
        le return point(a.x/b,a.y/b);
    }
    double norm(){
        return sqrt(sqr(x)+sqr(y));
    }
};
//�����������
double det(const point &a,const point &b){
    return a.x*b.y-a.y*b.x;
}
//�����������
double dot(const point &a,const point &b){
    return a.x*b.x+a.y*b.y;
}
//�����������
double dist(const point &a,const point &b){
    return (a-b).norm();
}
//op��ԭ����ʱ����תA����
point rotate_point(const point &p,double A){
    double tx=p.x,ty=p.y;
    return point(tx*cos(A)-ty*sin(A),tx*sin(A)+ty*cos(A));
}


//�߶���
struct line{
    point a,b;
    line(){}
    line(point x,point y):a(x),b(y){}
};
//��������a��b���ɵ��߶λ�ֱ��
line point_make_line(const point a,const point b){
    return line(a,b);
}
//��p���߶�st�ľ���
double dis_point_segment(const point p,const point s,const point t){
    if(cmp(dot(p-s,t-s))<0) return (p-s).norm();
    if(cmp(dot(p-t,s-t))<0) return (p-t).norm();
    return fabs(det(s-p,t-p)/dist(s,t));
}
//��p���߶�st�Ĵ��㣬������cp��
void PointProjLine(const point p,const point s,const point t,point &cp){
    double r=dot((t-s),(p-s))/dot(t-s,t-s);
    cp=s+r*(t-s);
}
//�ж�p�Ƿ����߶�st�ϣ������˵㣩
bool PointOnSegment(point p,point s,point t){
    return cmp(det(p-s,t-s))==0 && cmp(dot(p-s,p-t))<=0;
}
//�ж�a��b�Ƿ�ƽ��
bool parallel(line a,line b){
    return !cmp(det(a.a-a.b,b.a-b.b));
}
//�ж�a��b�Ƿ��ཻ������ཻ�򷵻�true�ҽ��㱣����res��
bool line_make_point(line a,line b,point &res){
    if(parallel(a,b)) return false;
    double s1=det(a.a-b.a,b.b-b.a);
    double s2=det(a.b-b.a,b.b-b.a);
    res=(s1*a.b-s2*a.a)/(s1-s2);
    return true;
}
//��ֱ��a�ط�����ƽ�ƾ���len�õ���ֱ��
line move_d(line a,const double &len){
    point d=a.b-a.a;
    d=d/d.norm();
    d=rotate_point(d,pi/2);
    return line(a.a+d*len,a.b+d*len);
}

int main(){

}