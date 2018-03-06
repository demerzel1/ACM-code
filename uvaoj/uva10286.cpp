#include<bits/stdc++.h>
using namespace std;
#define pi  acos(-1.0)
double f;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    double a=1.0*108*pi/(180*1.0);
    double b=1.0*63*pi/(180*1.0);
    double c=(double)sin(a)/(double)sin(b);
    while(cin>>f){
        cout<<setiosflags(ios::fixed)<<setprecision(10)<<c*f<<"\n";
    }
    return 0;
}
