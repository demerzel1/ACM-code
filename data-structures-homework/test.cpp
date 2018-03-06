#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
#define pi 3.1415926
int main(){
    double u,t;
    while(cin>>u>>t){
        double a=pi*18/sqrt(2*981*9.794);
        double r=sqrt((9*1.83*0.00001*2*0.001)/(2*981*9.794*t));
        double b=(1.83*0.00001*2*0.001)/(t*(1+8.23*0.001/(1.013*100000*r)));
        double cb=sqrt(b);
        double c=5*0.001/u;
        double ans=a*cb*cb*cb*c;
        cout<<ans<<endl;
    }
    return 0;
}
