#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a=1,b=1,c=1;
    for(int i=0;i<n-2;i++){
        c=(a+b)%10007;
        a=b;
        b=c;
    }
    printf("%d",c);
    return 0;
}
