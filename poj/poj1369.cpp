#include<iostream>
#include<ctime>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<ctime>
#define maxn 1005
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
static unsigned long rand_seed;

void mysrand(unsigned long seed) {
    rand_seed = seed;
}

unsigned long myrand() {
    rand_seed = (rand_seed * 16807L) % ((1 << 31) - 1);
    return rand_seed;
}
double X,Y;
typedef struct point{
    double x;
    double y;
    bool check(){
		if(x>-eps&&x<eps+X&&y>-eps&&y<eps+Y)
			return true;
		return false;
	}
}point;

point p[maxn];
point tp[50];
double tans[50];

double dis(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int T;

int M;

double cal(point p0){
    double ans=1e25;
    for(int i=0;i<M;i++)
        ans=min(ans,dis(p[i],p0));
    return ans;
}
//
//bool check(point x){
//    if(x.x>-eps&&x.x<eps+X&&x.y>-eps&&x.y<eps+Y)
//        return true;
//    return false;
//}

int main(){
    cin>>T;
    mysrand(51219);
//    srand(time(NULL));
    while(T--){
//        cin>>X>>Y>>M;
        scanf("%lf%lf%d",&X,&Y,&M);
        for(int i=0;i<M;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
//            cin>>p[i].x>>p[i].y;
        for(int i=0;i<15;i++){
            tp[i].x=(myrand()%1000+1)/1000.0*X;
            tp[i].y=(myrand()%1000+1)/1000.0*Y;
            tans[i]=cal(tp[i]);
        }
        double step=max(X,Y)/sqrt(1.0*M);
        while(step>1e-3){
            for(int i=0;i<15;i++){
                point cur,pre=tp[i];
                for(int j=0;j<35;j++){
                    double angle=(myrand()%1000+1)/1000.0*2*pi;
                    cur.x=pre.x+cos(angle)*step;
                    cur.y=pre.y+sin(angle)*step;
                    if(!cur.check())
                        continue;
                    double tmp=cal(cur);
                    if(tmp>tans[i]){
                        tp[i]=cur;
                        tans[i]=tmp;
                    }
                }
            }
            step*=0.85;
        }
        int ind=0;
        double ans=0;
        for(int i=0;i<15;i++){
            if(tans[i]>ans){
                ans=tans[i];
                ind=i;
            }
        }
        printf("The safest point is (%.1f, %.1f).\n",tp[ind].x,tp[ind].y);
    }
    return 0;
}
