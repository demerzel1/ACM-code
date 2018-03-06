#include<bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);
const double eps=1e-8;
int cmp(double x){
    if(fabs(x)<eps) return 0;
    if(x>0) return 1;
    return -1;
}
inline double sqr(double x){
    return x*x;
}
struct point{
    double x,y;
    point(){}
    point(double a,double b):x(a),y(b){}
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
point res;

struct line{
    point a,b;
    line(){}
    line(point x,point y):a(x),b(y){}
};

bool parallel(line a,line b){
    return !cmp(det(a.a-a.b,b.a-b.b));
}

bool line_make_point(line a,line b){
    if(parallel(a,b)) return false;
    double s1=det(a.a-b.a,b.b-b.a);
    double s2=det(a.b-b.a,b.b-b.a);
    res=(s1*a.b-s2*a.a)/(s1-s2);
    return true;
}
/////////////////////////////////////////////

bool judge(line a,line b){
    if(parallel(a,line(a.a,b.a))&&parallel(a,line(a.a,b.b)))
        return true;
    return false;
}

int main(){
//    clock_t start,finish;
//    start=clock();
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    printf("INTERSECTING LINES OUTPUT\n");
    while(n--){
        point a,b,c,d;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
        line la=line(a,b);
        line lb=line(c,d);
        if(parallel(la,lb)){
            if(judge(la,lb)){
                printf("LINE\n");
            }else
                printf("NONE\n");
        }else{
            line_make_point(la,lb);
            printf("POINT %.2f %.2f\n",res.x,res.y);
        }
    }
    printf("END OF OUTPUT\n");
//    finish=clock();
//    cout<<finish-start<<endl;
    return 0;
}

