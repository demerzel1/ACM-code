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
    if(n<2)return false;
    if(n==2)return true;
    if(!(n&1))return false;
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
    ll n;
    int s=20;
    while(~scanf("%lld",&n)) {
        if(n==1) {
            cout<<"is not a D_num\n";
            continue;
        }
        ind=0;
        Find(n);
        if(ind!=2&&ind!=3) {
            cout<<"is not a D_num"<<"\n";
            continue;
        }
        sort(factor,factor+ind);
        if(ind==2) {
            if(factor[0]!=factor[1])
                cout<<factor[0]<<" "<<factor[1]<<" "<<n<<"\n";
            else
                cout<<"is not a D_num"<<"\n";
        } else {
            if(factor[0]==factor[1]&&factor[1]==factor[2])
                cout<<factor[0]<<" "<<factor[0]*factor[0]<<" "<<n<<"\n";
            else
                cout<<"is not a D_num"<<"\n";
        }
    }
    return 0;
}
