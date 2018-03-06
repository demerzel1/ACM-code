#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
using ll=long long;
int main(){
    ll a,b;
    cin>>a>>b;
    ll t1,t2;
    ll ans=0;
    for(int i=1;i<=a;i++){
        t1=(i*b+1)%mod;
        t2=(b*(b-1)/2)%mod;
        ans=(ans+t1*t2)%mod;
    }
    cout<<ans;
    return 0;
}
