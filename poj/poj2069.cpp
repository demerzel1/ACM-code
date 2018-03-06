#include<iostream>
#include<ctime>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<algorithm>
#define eps 1e-7
using namespace std;
#define maxn 1005
const double pi = acos(-1.0);

typedef struct point{
    double x;
    double y;
    double z;
}point;

point p[maxn];
int n;

double dis(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

int main(){
   while(cin>>n&&n){
        for(int i=1;i<=n;i++)
            cin>>p[i].x>>p[i].y>>p[i].z;
        double step=100,ans=1e30;
        point ansp;
        ansp.x=ansp.y=ansp.z=0;
        int ind=0;
        while(step>eps){
            for(int i=1;i<=n;i++){
                if(dis(ansp,p[ind])<dis(ansp,p[i]))
                    ind=i;
            }
            double tans=dis(ansp,p[ind]);
            ans=min(ans,tans);
            ansp.x+=(p[ind].x-ansp.x)/tans*step;
            ansp.y+=(p[ind].y-ansp.y)/tans*step;
            ansp.z+=(p[ind].z-ansp.z)/tans*step;
            step*=0.98;
        }
        printf("%.5f\n",ans);
   }
    return 0;
}
