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
#include <iomanip>
#include <set>
#include <climits>
#include <ctime>
#include <complex>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=200005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a){return a<-eps? -1:a>eps;}

const int MOD=1e9+7;

struct mint{
    int x;
    mint():x(0){}
    mint(int s){ x=s;if(x<MOD && x>=0)return;
        x%=MOD;if(x<0)x+=MOD;
    }
    mint(ll s){int ts=s%MOD;if(ts<0)ts+=MOD;x=ts;}
    mint& operator+=(mint t){
        if( (x+=t.x) >=MOD)x-=MOD;return *this;}
    mint& operator-=(mint t){
        if( (x+=MOD-t.x) >=MOD)x-=MOD;return *this;}
    mint& operator*=(mint t){x=(ll)x*t.x%MOD;return *this;}
    mint& operator/=(mint t){return *this*=t.inv();}
    mint operator-()const{if(x)return MOD-x;return 0;}
    mint operator+(mint t)const{return mint(*this)+=t;}
    mint operator-(mint t)const{return mint(*this)-=t;}
    mint operator*(mint t)const{return mint(*this)*=t;}
    mint operator/(mint t)const{return mint(*this)/=t;}

    mint pow(ll k)const{
        mint r=1,a=x;
        for(;k;k>>=1,a*=a) if(k&1) r*=a;
        return r;
    }
    mint inv()const{return mint(x).pow(MOD-2);}
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ll _1,_2,n,_4;
    cin>>_1>>_2>>n>>_4;
    mint a=mint(_1);
    mint b=mint(_2);
    mint x=mint(_4);
    if(a.x==1){
        mint ans=x+b*n;
        cout<<ans.x<<endl;
        return 0;
    }
    mint ans=a.pow(n);
    ans*=x;
    mint t1=mint(1)-a.pow(n);
    mint t2=mint(1)-mint(a);
    t1/=t2;
    t1*=b;
    ans+=t1;
    cout<<ans.x<<endl;
    return 0;
}