#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll exgcd(ll a,ll b,ll &x,ll &y) {
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
    ll r=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return r;
}

int c;
ll n,l,r,t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x,y;
    cin>>c;
    while(c--){
        cin>>n>>l>>r>>t;
        t--;
        ll g=exgcd(l,r,x,y);
        ll k1=ceil(1.0*t*x/(r*1.0));
        ll k2=ceil(1.0*(-t)*y/(l*1.0));
        ll k=max(k1,k2);
        ll ans=(t*(y-x)+k*(r+l))/g;
   //     printf("t=%lld g=%lld x=%lld y=%lld k1=%lld k2=%lld ans=%lld\n",t,g,x,y,k1,k2,ans);
        if(t%g!=0){
            cout<<"uh-oh!\n";
            continue;
        }
        bool flag=false;
        int ind=1;
        for(int i=0;i<ans;i++){
            if(ind+r>n&&ind-l<1){
                flag=true;
                break;
            }
            if(ind+r<n)
                ind+=r;
            else
                ind-=l;
        }
        if(flag)
            cout<<"uh-oh!\n";
        else
            cout<<ans<<"\n";
    }
    return 0;
}
