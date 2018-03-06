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
    point() {}
    point(double a,double b):x(a),y(b) {}
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    friend point operator + (const point &a,const point &b) {
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator - (const point &a,const point &b) {
        return point(a.x-b.x,a.y-b.y);
    }
    friend bool operator == (const point &a,const point &b) {
        return cmp(a.x-b.x)==0&&cmp(a.y-b.y)==0;
    }
    friend point operator * (const point &a,const double &b) {
        return point(a.x*b,a.y*b);
    }
    friend point operator * (const double &a,const point &b) {
        return point(a*b.x,a*b.y);
    }
    friend point operator / (const point &a,const double &b) {
        return point(a.x/b,a.y/b);
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
    return (a-b).norm()+16.0;
}
//op绕原点逆时针旋转A弧度
point rotate_point(const point &p,double A) {
    double tx=p.x,ty=p.y;
    return point(tx*cos(A)-ty*sin(A),tx*sin(A)+ty*cos(A));
}

int mp[100000][9];
double ans[100000];
bool vis[9];
int nmp[9];
int n;
int ind=0;
double fans=INT_MAX;
vector<point> p;
int d;
void dfs(int pas,int x,double sum) {
    if(x==n){
        ans[d]=sum;
        if(fans>sum){
            fans=sum;
            ind=d;
        }
        for(int i=0;i<n;i++){
            mp[d][i]=nmp[i];
        }
   //     cout<<"sum="<<sum<<"d="<<d<<"\n";
        d++;
        return;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=true;
            nmp[x]=i;
            if(x==0){
                dfs(i,x+1,0);
            }else{
                dfs(i,x+1,sum+dist(p[i],p[pas]));
            }
            vis[i]=false;
        }
    }
}

int main() {
    int Case=0;
    while(cin>>n&&n) {
        Case++;
        ind=0;
        d=0;
        fans=INT_MAX;
        memset(mp,0,sizeof(mp));
        memset(ans,0,sizeof(ans));
        p.clear();
		for(int i=0; i<n; i++) {
            double a,b;
            cin>>a>>b;
            p.push_back(point(a,b));
        }
        memset(vis,false,sizeof(vis));
        memset(nmp,0,sizeof(nmp));
        dfs(-1,0,0);
        printf("**********************************************************\n");
        printf("Network #%d\n",Case);
        for(int i=0;i<n-1;i++){
      //      cout<<"mp="<<p[mp[index][i+1]].x<<"\n";
            printf("Cable requirement to connect (%.0f,%.0f) to (%.0f,%.0f) is %.2f feet.\n",p[mp[ind][i]].x,p[mp[ind][i]].y,p[mp[ind][i+1]].x,p[mp[ind][i+1]].y,dist(p[mp[ind][i]],p[mp[ind][i+1]]));
        }
        printf("Number of feet of cable required is %.2f.\n",fans);
    }
    return 0;
}
