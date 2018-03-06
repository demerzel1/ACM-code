#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#define MIN 1e-9
using namespace std;

int main(){
    int h,wc;
    while(1){
        scanf("%d%d",&h,&wc);
        if(h==0&&wc==0)
            break;
        int k=1;
        if(wc==1&&h==1){
            k=0;
        }else{

            for(k=1;k<50;k++){
            double x=pow(wc*1.0,1.0/k*1.0);
          //  printf("x=%f",x);
            if(fabs(pow(x+1.0,k*1.0)-h)<MIN){
              //  cout<<"sss"<<endl;
                break;
            }
        }
        }

        printf("k=%d\n",k);
        int N=(int)(pow(wc*1.0,1.0/k*1.0)+MIN);
        printf("N=%d\n",N);
        int bw[50];
        int sbw=0;
        for(int i=0;i<=k;i++){
            bw[i]=(int)(pow(N,i)+MIN);
            sbw+=bw[i];
        }
        sbw-=bw[k];
        int sumh=0;
        for(int i=0;i<=k;i++){
            int height=(int)(h*1.0/pow((N+1),i)+MIN);
          //  printf("%d\n",height);
            sumh+=bw[i]*height;
         //   printf("%d\n",sumh);
        }
        printf("%d %d\n",sbw,sumh);
    }
    return 0;
}
