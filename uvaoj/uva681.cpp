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


struct polygon_convex{
    vector<point> P;
    polygon_convex(int Size=0){
        P.resize(Size);
    }
};
bool comp_less(const point &a,const point &b){
    return cmp(a.y-b.y)<0||cmp(a.y-b.y)==0&&cmp(a.x-b.x)<0;
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


int containOlogn(const polygon_convex &a,const point &b){
    int n=a.P.size();
    point g=(a.P[0]+a.P[n/3]+a.P[2*n/3])/3.0;
    int l=0,r=n;
    while(l+1<r){
        int mid=(l+r)/2;
        if(cmp(det(a.P[l]-g,a.P[mid]-g))>0){
            if(cmp(det(a.P[l]-g,b-g))>=0&&cmp(det(a.P[mid]-g,b-g))<0){
                r=mid;
            }else
                l=mid;
        }else{
            if(cmp(det(a.P[l]-g,b-g))<0&&cmp(det(a.P[mid]-g,b-g))>=0)
                l=mid;
            else
                r=mid;
        }
    }
    r%=n;
    int z=cmp(det(a.P[r]-b,a.P[l]-b))-1;
    if(z==-2)
        return 1;
    return z;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    while(cin>>T){
        cout<<T<<"\n";
        for(int t=0;t<T;t++){
            int sss;
            if(t>0){
                cin>>sss;
                cout<<sss<<"\n";
            }

            vector<point> v;
            int n;
            cin>>n;
            double x,y;
            for(int i=0;i<n;i++){
                cin>>x>>y;
                v.push_back(point(x,y));
            }
            polygon_convex pc=convex_hull(v);
            int sz=pc.P.size();
            cout<<sz+1<<"\n";
            for(int i=0;i<sz;i++){
                cout<<pc.P[i].x<<" "<<pc.P[i].y<<"\n";
            }
            cout<<pc.P[0].x<<" "<<pc.P[0].y<<"\n";
        }
    }
    return 0;
}
