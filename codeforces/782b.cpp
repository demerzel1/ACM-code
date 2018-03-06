#include<bits/stdc++.h>
using namespace std;
#define maxn 60005
int x[maxn];
int v[maxn];
const double eps=1e-7;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>x[i];
    for(int i=0;i<n;i++)
        cin>>v[i];
    double l=0,r=1e9;
    while(r-l>=eps){
        double t=(r+l)/2;
        double L=-3e9,H=3e9;
        for(int i=0;i<n;i++){
            H=min(H,x[i]+t*v[i]);
            L=max(L,x[i]-t*v[i]);
        }
        if(H-L>=eps)
            r=t;
        else
            l=t;
    }
    cout<<fixed<<setprecision(10)<<(r+l)/2<<"\n";
    return 0;
}
