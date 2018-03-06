#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
const double pi = acos(-1.0);

typedef struct point{
    double x;
    double y;
}point;

point p[maxn];
double X,Y;
double minx,miny,maxx,maxy;
int n;
double r;
double ans;

double dis(point a,point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double cal(point x){
    double t=INT_MIN;
    for(int i=0;i<n;i++){
        t=max(dis(x,p[i]),t);
    }
    return t;
}

int main(){
    point ansp,tansp;
    while(cin>>X>>Y>>n){
        minx=miny=INT_MAX;
        maxx=maxy=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>p[i].x>>p[i].y;
            minx=min(p[i].x,minx);
            miny=min(p[i].y,miny);
            maxx=max(p[i].x,maxx);
            maxy=max(p[i].y,maxy);
        }
        ansp.x=(minx+maxx)/2;
        ansp.y=(miny+maxy)/2;
        tansp=ansp;
        r=sqrt((maxx-minx)*(maxx-minx)+(maxy-miny)*(maxy-miny))/2;
        ans=cal(ansp);
        double tans=ans;
        while(true){
            for(double j=0;j<=2*pi;j+=0.1){
                point tp;
                tp.x=ansp.x+r*cos(j);
                tp.y=ansp.y+r*sin(j);
                double tt=cal(tp);
                if(tt<tans){
                    tansp=tp;
                    tans=tt;
                }
            }
            if(fabs(ans-tans)<0.01&&r<0.0001)
                break;
            if(tans<ans){
                ans=tans;
                ansp=tansp;
            }else
                r*=0.7;
        }
        printf("(%.1f,%.1f).\n", ansp.x, ansp.y);
        printf("%.1f\n", sqrt(ans));
    }
    return 0;
}
