#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int a,b,c;
    for(int i=100; i<1000; i++) {
        c=i%10;
        b=i/10%10;
        a=i/100;
        if(i==(a*a*a+b*b*b+c*c*c)) {
            printf("%d\n",i);
        }
    }
    return 0;
}
