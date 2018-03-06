#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    int h,m,s;
    s=t%60;
    m=((t-s)/60)%60;
    h=(t-s-m*60)/3600;
    printf("%d:%d:%d",h,m,s);
    return 0;
}
