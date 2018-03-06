#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <ctime>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
#include<climits>
using namespace std;
typedef long long ll;
ll ind;
ll factor[110000];
#define uint unsigned int
#define ull unsigned long long
ull ans=LLONG_MAX;
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

bool witness(ll n,ll a,ll u,int cnt) {
    ll x=mod_pow(a,u,n);
    ll t=x;
    for(int i=1; i<=cnt; i++) {
        t=x;
        x=mod_mul(x,x,n);
        if(x==1&&t!=1&&t!=n-1)
            return true;
    }
    if(x!=1)
        return true;
    return false;
}

bool miller_rabin(ll n,int s) {
    int cnt=0;
    ll u=n-1;
    while(!(u&1)) {
        cnt++;
        u=u>>1;
    }
    ll a;
    for(int i=1; i<=s; i++) {
        a=rand()%(n-1)+1;
        if(witness(n,a,u,cnt))
            return false;
    }
    return true;
}

ll pollarn_rho(ll n,ll c) {
    if(!(n&1))
        return 2;
    ll x=rand()%n;
    ll y=x;
    ll i=1;
    ll k=2;
    while(true) {
        i++;
        x=(mod_mul(x,x,n)+c)%n;
        ll d=gcd(y-x+n,n);
        if(d!=1&&d!=n)
            return d;
        if(y==x)
            return n;
        if(i==k) {
            y=x;
            k+=k;
        }
    }
}

void Find(ll n) {
    if(miller_rabin(n,20)) {
        factor[ind++]=n;
        return;
    }
    ll p=n;
    while(p>=n)
        p=pollarn_rho(p,(ll)(rand()%(n-1)+1));
    Find(p);
    Find(n/p);
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    srand(time(NULL));
    ll n;
    int T;
    int s=20;
    scanf("%d",&T);
    while(T--) {
        scanf("%lld",&n);
        ind=0;
        Find(n);
        if(ind==1) {
            printf("Prime\n");
            continue;
        }
        ll tp=10000000000LL;
        for(int i = 0; i < ind; i++) {
            if(tp > factor[i])
                tp = factor[i];
        }
        printf("%lld\n",tp);
    }
    return 0;
}
