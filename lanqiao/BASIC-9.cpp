#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=10000;i<100000;i++){
        int a,b,c,d,e;
        a=i/10000;
        b=(i%10000)/1000;
        c=(i%1000)/100;
        d=(i%100)/10;
        e=i%10;
        if(a==e&&b==d&&(a+b+c+d+e==n)){
            printf("%d\n",i);
        }
    }
    for(int i=100000;i<1000000;i++){
        int a,b,c,d,e,f;
        f=i/100000;
        a=i/10000%10;
        b=(i%10000)/1000;
        c=(i%1000)/100;
        d=(i%100)/10;
        e=i%10;
        if(f==e&&a==d&&b==c&&(a+b+c+d+e+f==n)){
            printf("%d\n",i);
        }
    }
    return 0;
}
