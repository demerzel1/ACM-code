#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll mod_mul(ll x,ll y,ll mod) {
    x%=mod;
    y%=mod;
    ll t=0;
    while(y) {
        if(y&1)
            t=(t+x)%mod;
        x=(x<<1)%mod;
        y>>=1;
    }
    return t;
}

ll mod_pow(ll x,ll n,ll mod) {
    x%=mod;
    ll res=1;
    while(n) {
        if(n&1)
            res=mod_mul(res,x,mod);
        x=mod_mul(x,x,mod);
        n>>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int b,p,m;
    while(cin>>b){
        cin>>p>>m;
        cout<<mod_pow(b,p,m)<<"\n";;
    }
    return 0;
}
