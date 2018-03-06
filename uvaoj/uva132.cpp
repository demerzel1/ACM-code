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
    int index;
    point() {}
    point(double a,double b,int c):x(a),y(b),index(c) {}
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    friend point operator + (const point &a,const point &b) {
        return point(a.x+b.x,a.y+b.y,a.index+b.index);
    }
    friend point operator - (const point &a,const point &b) {
        return point(a.x-b.x,a.y-b.y,a.index);
    }
    friend bool operator == (const point &a,const point &b) {
        return cmp(a.x-b.x)==0&&cmp(a.y-b.y)==0;
    }
    friend point operator * (const point &a,const double &b) {
        return point(a.x*b,a.y*b,a.index);
    }
    friend point operator * (const double &a,const point &b) {
        return point(a*b.x,a*b.y,b.index);
    }
    friend point operator / (const point &a,const double &b) {
        return point(a.x/b,a.y/b,a.index);
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
bool containOn(const polygon_convex &a,const point &b) {
    int n=a.P.size();
#define next(i) ((i+1)%n)
    int sign=0;
    for(int i=0; i<n; i++) {
        int x=cmp(det(a.P[i]-b,a.P[next(i)]-b));
        if(x) {
            if(sign) {
                if(sign!=x) return false;
            } else
                sign=x;
        }
    }
    return true;
}

string obj;
vector<point> a;
point center;
polygon_convex tubao;

bool point_to_seg(point p1,point p2,point p3) {
    double A=dist(p1,p3);
    double B=dist(p2,p3);
    double C=dist(p1,p2);
  //  cout<<A<<" "<<B<<" "<<C<<"\n";
    return cmp(A*A+C*C-B*B)>=0&&cmp(B*B+C*C-A*A)>=0;
}

bool on_seg(point s,point t,point p) {
    return cmp(det(p-s,t-s))==0 && cmp(dot(p-s,p-t))<=0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>obj&&obj!="#") {
        a.clear();
        tubao.P.clear();
        cin>>center.x>>center.y;
        int cnt=1;
        while(true) {
            double n1,n2;
            cin>>n1>>n2;
            if(n1==0&&n2==0)
                break;
            point p=point(n1,n2,cnt);
            a.push_back(p);
            cnt++;
        }
        //  cout<<a.size()<<"\n";
        tubao=convex_hull(a);
     //   cout<<tubao.P.size()<<"\n";
//     for(int i=0; i<tubao.P.size(); i++)
//            cout<<tubao.P[i].x<<" "<<tubao.P[i].y<<" "<<tubao.P[i].index<<"\n";
        int sz=tubao.P.size();
        int n=a.size();
      //  cout<<"n="<<n<<"\n";
        int ans=INT_MAX;
        for(int i=1; i<sz; i++) {
         //   cout<<333<<"\n";
            if(point_to_seg(tubao.P[i-1],tubao.P[i],center)) {
             //   cout<<222<<"\n";
                int t=max(tubao.P[i-1].index,tubao.P[i].index);
              //   cout<<111<<" "<<t<<"\n";
                for(int j=0; j<n; j++) {
                    if(on_seg(tubao.P[i-1],tubao.P[i],a[j])) {
                        t=max(t,a[j].index);
                   //     cout<<"t="<<t<<" "<<j<<"\n";
                    }
                }
             //   cout<<"final "<<t<<"\n";
                ans=min(t,ans);
            }
        }
        if(point_to_seg(tubao.P[0],tubao.P[sz-1],center)) {
              //  cout<<222<<"\n";
                int t=max(tubao.P[0].index,tubao.P[sz-1].index);
            //     cout<<111<<" "<<t<<"\n";
                for(int j=0; j<n; j++) {
                    if(on_seg(tubao.P[0],tubao.P[sz-1],a[j])) {
                        t=max(t,a[j].index);
                    }
                }
                ans=min(t,ans);
            }
        cout<<obj<<" "<<ans<<"\n";
    }
    return 0;
}
