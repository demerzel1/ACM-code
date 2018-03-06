#include<bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);
const double eps=1e-8;
//doubleÀàÐÍµÄÊý£¬ÅÐ¶Ï·ûºÅ
int cmp(double x){
    if(fabs(x)<eps) return 0;
    if(x>0) return 1;
    return -1;
}
//¶þÎ¬µãÀà£¬¿É½øÐÐÏòÁ¿ÔËËã
//¼ÆËãÆ½·½
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
//¼ÆËãÏòÁ¿²æ»ý
double det(const point &a,const point &b){
    return a.x*b.y-a.y*b.x;
}
//¼ÆËãÏòÁ¿µã»ý
double dot(const point &a,const point &b){
    return a.x*b.x+a.y*b.y;
}
//¼ÆËãÁ½µã¾àÀë
double dist(const point &a,const point &b){
    return (a-b).norm();
}
//opÈÆÔ­µãÄæÊ±ÕëÐý×ªA»¡¶È
point rotate_point(const point &p,double A){
    double tx=p.x,ty=p.y;
    return point(tx*cos(A)-ty*sin(A),tx*sin(A)+ty*cos(A));
}

point res;
//Ïß¶ÎÀà
struct line{
    point a,b;
    line(){}
    line(point x,point y):a(x),b(y){}
};
//ÓÃÁ½¸öµãa£¬bÉú³ÉµÄÏß¶Î»òÖ±Ïß
line point_make_line(const point a,const point b){
    return line(a,b);
}
//Çópµ½Ïß¶ÎstµÄ¾àÀë
double dis_point_segment(const point p,const point s,const point t){
    if(cmp(dot(p-s,t-s))<0) return (p-s).norm();
    if(cmp(dot(p-t,s-t))<0) return (p-t).norm();
    return fabs(det(s-p,t-p)/dist(s,t));
}
//Çópµ½Ïß¶ÎstµÄ´¹×ã£¬±£´æÔÚcpÖÐ
void PointProjLine(const point p,const point s,const point t,point &cp){
    double r=dot((t-s),(p-s))/dot(t-s,t-s);
    cp=s+r*(t-s);
}
//ÅÐ¶ÏpÊÇ·ñÔÚÏß¶ÎstÉÏ£¨°üÀ¨¶Ëµã£©
bool PointOnSegment(point p,point s,point t){
    return cmp(det(p-s,t-s))==0 && cmp(dot(p-s,p-t))<=0;
}
//ÅÐ¶Ïa£¬bÊÇ·ñÆ½ÐÐ
bool parallel(line a,line b){
    return !cmp(det(a.a-a.b,b.a-b.b));
}
//ÅÐ¶Ïa£¬bÊÇ·ñÏà½»£¬Èç¹ûÏà½»Ôò·µ»ØtrueÇÒ½»µã±£´æÔÚresÖÐ
bool line_make_point(line a,line b){
    if(parallel(a,b)) return false;
    double s1=det(a.a-b.a,b.b-b.a);
    double s2=det(a.b-b.a,b.b-b.a);
    res=(s1*a.b-s2*a.a)/(s1-s2);
    return true;
}
//½«Ö±ÏßaÑØ·¨ÏòÁ¿Æ½ÒÆ¾àÀëlenµÃµ½µÄÖ±Ïß
line move_d(line a,const double &len){
    point d=a.b-a.a;
    d=d/d.norm();
    d=rotate_point(d,pi/2);
    return line(a.a+d*len,a.b+d*len);
}

//////////////////////////////////////////////////

bool judge(line a,line b){
    if(parallel(a,b)&&(PointOnSegment(a.a,b.a,b.b)||PointOnSegment(a.b,b.a,b.b)||PointOnSegment(b.a,a.a,a.b)||PointOnSegment(b.b,a.a,a.b)))
        return true;
    if(line_make_point(a,b)){
        if(PointOnSegment(res,a.a,a.b)&&PointOnSegment(res,b.a,b.b))
            return true;
        else
            return false;
    }else
        return false;
}


bool ans[105];
vector<line> v;
point a,b;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(ans,false,sizeof(ans));
        v.clear();
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
            line l=line(a,b);
            v.push_back(l);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                if(judge(v[i],v[j])){
                    ans[i]=true;
                    ans[j]=true;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
            if(ans[i]==false)
                cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}

