#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define maxn 105
#define eps 1e-8

struct Line{
    double x1,y1,x2,y2;
}l[maxn];
int n;

double dis(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double cross(doubl e x1,double y1,double x2,double y2,double x,double y){
    return (x2-x1)*(y-y1)-(y2-y1)*(x-x1);
}

bool judge(double x1,double y1,double x2,double y2){
    if(dis(x1,y1,x2,y2)<eps) return false;
    for(int i=0;i<n;i++){
        if(cross(x1,y1,x2,y2,l[i].x1,l[i].y1)*cross(x1,y1,x2,y2,l[i].x2,l[i].y2)>eps)
            return false;
    }
    return true;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
        }
        if(n==1){
            printf("Yes!\n");
            continue;
        }
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(judge(l[i].x1,l[i].y1,l[j].x1,l[j].y1)||
                   judge(l[i].x1,l[i].y1,l[j].x2,l[j].y2)||
                   judge(l[i].x2,l[i].y2,l[j].x1,l[j].y1)||
                   judge(l[i].x2,l[i].y2,l[j].x2,l[j].y2)){
                    flag=true;
                    break;
                   }
            }
            if(flag)
                break;
        }
        if(flag)
            printf("Yes!\n");
        else
            printf("No!\n");
    }
    return 0;
}
