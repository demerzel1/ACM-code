#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    for(int i=1000;i<10000;i++){
        int a,b,c,d;
        a=i/1000;
        b=i/100%10;
        c=i/10%10;
        d=i%10;
        if(a==d&&b==c){
            printf("%d\n",i);
        }
    }
    return 0;
}

