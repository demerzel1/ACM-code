#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define modd 1000000007
#define maxn 1000005

ll gcd(ll a,ll b) {
    return b==0?a:gcd(b,a%b);
}

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

int ans;
bool vis[maxn];

int main(){
    int p,k;
    scanf("%d%d",&p,&k);
    if(k==0){
        cout<<mod_pow(p,p-1,modd);
        return 0;
    }
    if(k==1){
        cout<<mod_pow(p,p,modd);
        return 0;
    }
    for(int i=1;i<p;i++){
        if(vis[i])
            continue;
        ans++;
        int x=i;
        while(!vis[x]){
            vis[x]=true;
            x=(ll)k*(ll)x%p;
        }
    }
    cout<<mod_pow(p,ans,modd);
    return 0;
}
