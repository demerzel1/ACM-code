#include<stdio.h>
#include<string.h>
#include<iostream>
using  namespace std;
const int Maxn=25000000;
char h[Maxn];
int main(){
    int i,j,k,s,t;
    int a1,a2,a3,a4,a5;
    while(scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5)!=EOF){
        s=0;
       memset(h,0,sizeof(h));
        for(i=-50;i<=50;i++)
            for(j=-50;j<=50;j++)
                if(i!=0&&j!=0){
                    t=a1*i*i*i+a2*j*j*j;
                    h[t+Maxn/2]++;
                }
        for(i=-50;i<=50;i++)
            for(j=-50;j<=50;j++)
                for(k=-50;k<=50;k++)
                    if(i!=0&&j!=0&&k!=0){
                        t=a3*i*i*i+a4*j*j*j+a5*k*k*k;
                        if(t>=-Maxn/2&&t<=Maxn/2)
                            s+=h[-t+Maxn/2];
                    }
       printf("%d\n",s);
   }
   return 0;
}
