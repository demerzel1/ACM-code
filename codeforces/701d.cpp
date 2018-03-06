#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    double l,v1,v2;
    cin>>n>>l>>v1>>v2>>k;
    int p=(n-1)/k+1;
    double t=l/((double)p*v2-(v2-v1)/(v2+v1)*v2*((double)p-1));
    cout<<setiosflags(ios::fixed)<<setprecision(10)<<(l-v2*t)/v1+t;
    return 0;
}
