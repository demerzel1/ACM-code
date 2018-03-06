#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    double a,b;
    cin>>a>>b;
    if(a-b<=1e-8&&a-b>=-1e-8)
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
