#include<stdio.h>
#include<math.h>
#include<string.h>
const double pi = acos(-1.0);
struct point {
    double x,y;
}p[1010];
int n;
point mid,tmid;
double R,xmin,ymin,xmax,ymax;
double ans,tans;
double dis(point a, point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
void solve(double x,double y)
{
    double max=0;
    point tp;
    tp.x=x;
    tp.y=y;
    for(int i=0;i<n;i++)
    {
        double tmp=dis(p[i],tp);
            if(tmp>max)
                max=tmp;
    }
    if(max<tans)
    {
        tans=max;
        tmid=tp;
    }
}
int main()
{
    int X,Y,i,k;
    double j;
    while(scanf("%d%d%d",&X,&Y,&n)!=EOF)
    {
       // printf("n=%d\n",n);
        xmin=10000;ymin=10000;xmax=0;ymax=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            if(p[i].x<xmin) xmin=p[i].x;
            if(p[i].y<xmin) xmin=p[i].y;
            if(p[i].x>xmax) xmax=p[i].x;
            if(p[i].y>ymax) ymax=p[i].y;
        }
        mid.x=(xmin+xmax)/2;
        mid.y=(ymin+ymax)/2;
        tmid=mid;
        R=sqrt((xmax-xmin)*(xmax-xmin)+(ymax-ymin)*(ymax-ymin))/2;
        for(i=0;i<n;i++)
        {
            double tmp=dis(mid,p[i]);
            if(tmp>tans)
                tans=tmp;
        }
        ans=tans;
        while(1)
        {
            for(double j=0;j<=2*pi;j+=0.1)
            {
                solve(mid.x+R*sin(j),mid.y+R*cos(j));
            }
            if(fabs(ans-tans)<0.01&&R<0.0001) break;
            if(tans<ans)
            {
                ans=tans;
                mid=tmid;
            }
            else R*=0.7;
        }
        printf("(%.1lf,%.1lf).\n", mid.x, mid.y);
        printf("%.1lf\n", sqrt(ans));
    }
    return 0;
}
