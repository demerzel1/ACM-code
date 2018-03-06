#include<bits/stdc++.h>
using namespace std;

int num[105];

void init(){
    for(int i=1;i<100;i+=2){
         num[i]=(i*i+1)/2;
    }
}

int main(){
    init();
    int x;
    scanf("%d",&x);
    if(x==1)
        printf("1");
    if(x==3)
        printf("5");
    else{
        for(int i=1;i<100;i+=2){
            if(num[i]<x&&num[i+2]>=x){
                 printf("%d",i+2);
                 break;
            }

        }
    }
    return 0;
}
