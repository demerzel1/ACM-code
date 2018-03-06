#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

const int Max=50000;
int N;
int n,dat[2*Max-1];
int c=1;
void init(int n_){
    n=1;
    while(n<n_) n*=2;
    for(int i=0;i<2*n-1;i++)
        dat[i]=Max;
}
void update(int k,int a){
    k+=n-1;
    dat[k]=a;
    while(k>0){
        k=(k-1)/2;
        dat[k]=min(dat[k*2+1],dat[k*2+2]);
    }
}
int query(int k,int j,int a){
    printf("queryÀ² k=%d j=%d a=%d c=%d\n",k,j,a,c);
    if(k>=j+N-1){
            printf("returned c=%d\n",c);
            return 0;
    }
    if(k>=N-1&&dat[k]<=a){
        printf("returned 1 c=%d\n",c);

        return 1;
    }
    else{
        if(dat[k]<=a){
            if(dat[2*k+1]<=a){
                c+=query(2*k+1,j,a);
                printf("case a. c=%d\n",c);
            }
            if(dat[2*k+2]<=a){
                c+=query(2*k+2,j,a);
                printf("case b.c=%d\n",c);
            }
        }
    }
}
int main(){
    int x,y;
    scanf("%d",&N);
    init(N);
    for(int i=0;i<N;i++){
        scanf("%d%d",&x,&y);
        update(i,x);
        query(0,i,x);
        printf("%d\n",c);
        c=1;
    }
    return 0;
}
