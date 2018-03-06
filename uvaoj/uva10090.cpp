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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    ll n1,n2,c1,c2,x,y;
    ll g;
    while(true){
        cin>>n;
        if(n==0)
            break;
        cin>>c1>>n1>>c2>>n2;
        g=exgcd(n1,n2,x,y);
        ll k1=ceil((double)(-n*x)/(double)n2);
        ll k2=floor((double)(n*y)/(double)n1);
        if(n%g!=0||(k1>k2)){
            cout<<"failed\n";
            continue;
        }
        ll k;
        if(c1*n2>=c2*n1)
            k=k1;
        else
            k=k2;
        x=n*x/g+n2*k/g;
        y=n*y/g-n1*k/g;
        cout<<x<<" "<<y<<"\n";
    }
    return 0;
}
