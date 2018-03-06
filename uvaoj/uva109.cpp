#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-8;
#define maxn 105
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

bool containOn(const polygon_convex &a,const point &b){
    int n=a.P.size();
    #define next(i) ((i+1)%n)
    int sign=0;
    for(int i=0;i<n;i++){
        int x=cmp(det(a.P[i]-b,a.P[next(i)]-b));
        if(x){
            if(sign){
                if(sign!=x) return false;
            }else
                sign=x;
        }
    }
    return true;
}

polygon_convex pc[maxn];
bool vis[maxn];

int main(){
    int n;
    int ind=0;
    while(cin>>n&&n!=-1){
        point p;
        vector<point> v;
        for(int i=0;i<n;i++){
            cin>>p.x>>p.y;
            v.push_back(p);
        }
        pc[ind]=convex_hull(v);
        ind++;
    }
    point dd;
//    printf("1111111\n");
    double sum=0;
    while(cin>>dd.x>>dd.y){
        for(int i=0;i<ind;i++){
            if(!vis[i]&&containOn(pc[i],dd)){
                vis[i]=true;
                sum-=pc[i].area();
            }
        }
    }
    cout<<fixed<<setprecision(2)<<sum<<"\n";
    return 0;
}
