#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    double price;
    double rate;
    scanf("%lf%lf",&price,&rate);
    price=price*(rate/10);
    int x;
    x=(int)(price/10+0.5)*10;
    printf("%d",x);
    return 0;
}
