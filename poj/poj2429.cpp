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
ll ans[110000];
#define uint unsigned int
#define ull unsigned long long
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
    if(n==1){
        return;
    }
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

ll sans=1;

void f(int i,ll x,ll sq,int inde){
    if(i==inde) return;
    if(x>sq)    return;
    if(x>sans&&x<=sq)
        sans=x;
    f(i+1,x,sq,inde);
    x*=ans[i];
    if(x>sans&&x<=sq)
        sans=x;
    f(i+1,x,sq,inde);
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    ll a,b;
    int s=10;
    while(~scanf("%lld%lld",&a,&b)) {
        if(a==1&&b==1){
            printf("1 1\n");
            continue;
        }
        if(a>b){
            printf("%lld 0\n",a);
            continue;
        }
        ind=0;
        memset(ans,0,sizeof(ans));
        b/=a;
       // printf("b=%d\n",b);
        Find(b);
      //  printf("ind=%d\n",ind);
        factor[ind++]=b;
        int nhgj=0;
        sort(factor,factor+ind);
      //  printf("ind=%d\n",ind);
        for(int i=0;i<ind;i++){
            if(i==0)
                ans[nhgj++]=factor[0];
            else if(i>0&&factor[i]!=factor[i-1]){
                ans[nhgj++]=factor[i];
            }else if(i>0&&factor[i]==factor[i-1]){
                ans[nhgj-1]*=factor[i];
            }
        }
        sans=1;
        f(0,1,(ll)sqrt(b*1.0),nhgj);
       // cout<<sans<<"\n";
        cout<<sans*a<<" "<<b/sans*a<<"\n";
    }
    return 0;
}
