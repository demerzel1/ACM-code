#include<bits/stdc++.h>
using namespace std;
#define Pi 3.1415926535

int main(){
   // ios::sync_with_stdio(false);
    cin.tie(0);
    double d,h,v,e;
    cin>>d>>h>>v>>e;
    if(Pi*d*d*e/4>=v){
        cout<<"NO";
    }else{
        double ans=Pi*d*d*h/4/(v-Pi*d*d*e/4);
        cout<<"YES\n";
        printf("%.12f\n",ans);
    }
    return 0;
}
