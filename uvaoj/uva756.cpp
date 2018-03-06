#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll maxn = 10;
ll a[maxn], m[maxn], n;
ll d;

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

//
//void exgcd(ll a,ll b,ll &d,ll &x,ll &y)
//{
//    if(b==0){
//        d=a;
//        x=1,y=0;
//    }
//    else{
//        exgcd(b,a%b,d,y,x);
//        y-=(a/b)*x;
//    }
//}
//ll CRT(ll *a,ll *m,int n)
//{
//    ll M=1,d,y,x=0;
//    for(int i=0;i<n;i++) M*=m[i];
//    for(int i=0;i<n;i++){
//        ll w=M/m[i];
//        exgcd(m[i],w,d,d,y);
//        x=(x+y*w*a[i])%M;
//    }
//    return (x+M)%M;
//}

ll CRT(ll a[], ll m[], ll n) {
    ll M = 1;
    for(int i = 0; i < n; i++) M *= m[i];
    ll ret = 0;
    for(int i = 0; i < n; i++) {
        ll x, y;
        ll tm = M / m[i];
        exgcd(tm, m[i], x, y);
        ret = (ret + tm * x * a[i]) % M;
    }
    return (ret + M) % M;
}

int main(){
    m[0]=23;
    m[1]=28;
    m[2]=33;
    int cas=0;
    while(cin>>a[0]>>a[1]>>a[2]>>d){
        cas++;
        if(a[0]==-1&&a[1]==-1&&a[2]==-1&&d==-1)
            break;
        ll ans=CRT(a,m,3);
        ll M=(ll)(m[0]*m[1]*m[2]);
        while(ans-d<0||ans==0)
            ans+=M;
        cout<<"Case "<<cas<<": the next triple peak occurs in "<<ans-d<<" days.\n";
    }
    return 0;
}
