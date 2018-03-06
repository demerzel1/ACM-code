#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
    int y;
    scanf("%d",&y);
    if((y%400==0)||(y%4==0&&y%100!=0))
        printf("yes");
    else
        printf("no");
    return 0;
}
