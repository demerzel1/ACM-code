#include <bits/stdc++.h>
using namespace std;

using ll=long long;

ll n,s;

bool judge (ll x);

int main(){
    cin>>n>>s;
    ll l=s,r=n;
    while(r-l>3){
     //   cout<<l<<' '<<r<<endl;
        ll mid=(r+l)>>1;
        if(judge(mid))
            r=mid;
        else
            l=mid;
    }
    ll ans=-1;
    for(ll i=l;i<=r;i++){
        if(judge(i)){
            ans=i;
            break;
        }
    }
    if(ans==-1){
        cout<<0<<endl;
    } else
        cout<<n-ans+1<<endl;
    return 0;
}

bool judge (ll x) {
    ll sum=0;
    ll t=x;
    while(t){
        sum+=t%10;
        t/=10;
    }
    return x - sum >= s;
}