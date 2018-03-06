#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int x=0,y=0;
    int sum=100000000;
    scanf("%d",&n);
    for(int i=0;i<=n/7;i++){
        int a=(n-i*7)/4;
 //       printf()
     //   printf("%d ",a);
        if(a*4+i*7==n){
            if(sum>(a+i)){
                x=a;
                y=i;
            }
        }
    }
    if(x==0&&y==0){
        printf("-1");
        return 0;
    }

    for(int i=0;i<x;i++)
        putchar('4');
    for(int i=0;i<y;i++)
        putchar('7');
    return 0;
}
