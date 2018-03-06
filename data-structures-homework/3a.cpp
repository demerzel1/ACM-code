#include<cstdio>
#include<cstring>
void sbt(int lu,int ld,int ru,int rd,int u,int d){
    if(((lu+ru)*d)==((ld+rd)*u)){
        printf("\n");
        return;
    }
    if((lu+ru)*d<(ld+rd)*u){
     //   printf("%d %d %d %d\n",lu+ru,d,ld+rd,u);
        printf("R");
        sbt(lu+ru,ld+rd,ru,rd,u,d);
    }else{
     //   printf("%d %d %d %d\n",lu+ru,d,ld+rd,u);
        printf("L");
        sbt(lu,ld,lu+ru,ld+rd,u,d);
    }
}
int main(){
    int m,n;
    while(1){
        scanf("%d%d",&n,&m);
        if(n==1&&m==1)
            break;
        sbt(0,1,1,0,n,m);
    }

    return 0;
}
