#include<bits/stdc++.h>
using namespace std;
int da[105];
int db[105];
int main(){
    int n,l;
    scanf("%d%d",&n,&l);
    int a;
    scanf("%d",&a);
    int x;
    int b=a;
    for(int i=0;i<n-1;i++){
        scanf("%d",&x);
        da[i]=x-a;
        a=x;
    }
    da[n-1]=l-x+b;
    scanf("%d",&a);
    b=a;
 //   printf("a=%d\n",a);
    for(int i=0;i<n-1;i++){
        scanf("%d",&x);
   //     printf("x%d\n",x);
        db[i]=x-a;
        a=x;
    }
    db[n-1]=l-x+b;
//    for(int i=0;i<n;i++){
//        printf("%d ",da[i]);
//    }
//    printf("\n");
//    for(int i=0;i<n;i++){
//        printf("%d ",db[i]);
//    }
   // printf("\n");
     bool flag=false;
    if(n==1)
        printf("YES");
    else{
        for(int i=0;i<n-1;i++){
            if(da[0]==db[i]){
                int k=i;
                int j;
                for(j=0;j<n-i;j++){
                    if(da[j]==db[k]){
               //         printf("j=%d k=%d\n",j,k);
                        flag=true;
                        k++;
                    }else{
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    for(int m=0;m<i;m++){
                        if(da[j]==db[m]){
                            flag=true;
                            j++;
                        }else{
                            flag=false;
                            break;
                        }
                    }
                }
                if(flag)
                    break;
            }
        }
        if(flag)
            printf("YES");
        else
            printf("NO");
    }
    return 0;
}

