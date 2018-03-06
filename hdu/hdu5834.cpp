#include <bits/stdc++.h>
using namespace std;
typedef double ld;
typedef long long int64;
typedef signed int sint;
typedef unsigned int uint;
typedef signed long long sint64;
typedef unsigned long long uint64;
typedef pair<int,int>ii;
const int MAXN=1111;
const int MOD=1000000007;
const int INF=0x7f7f7f7f;
int cases;
 
//质数时适用
struct mint{
    int x;
    mint():x(0){}
    mint(int s){
        x=s;if(x<MOD && x>=0)return; 
        x%=MOD;if(x<0)x+=MOD;
    }
    mint(int64 s){
        if(s<MOD && s>0){x=s;return;}
        x=s%MOD;if(x<0)x+=MOD;
    }
    mint& operator+=(mint t){if( (x+=t.x) >=MOD)    x-=MOD;return *this;}
    mint& operator-=(mint t){if( (x+=MOD-t.x) >=MOD)x-=MOD;return *this;}
    mint& operator*=(mint t){x=(int64)x*t.x%MOD;return *this;}
    mint& operator/=(mint t){return *this*=t.inv();}
    mint operator-()const{mint t;t.x=(x==0? 0:MOD-x);return t;}
    mint operator+(mint t)const{return mint(*this)+=t;}//-、*、/相同
    mint operator-(mint t)const{return mint(*this)-=t;}
    mint operator*(mint t)const{return mint(*this)*=t;}
    mint operator/(mint t)const{return mint(*this)/=t;}
    mint pow(int64 k)const{
        mint r=1,a=x;
        for(;k;k>>=1,a*=a) if(k&1) r*=a;
        return r;
    }
    mint inv()const{
        int a=x,b=MOD,u=1,v=0,t;
        while(b) { t=a/b; a-=t*b;swap(a,b); u-=t*v;swap(u,v);}
        if(u<0)u+=MOD; return mint(u);
    }
};
vector<mint> fact,factinv;
void LucasInit(int N) {
    N=min(N,MOD-1); fact.resize(N+1);factinv.resize(N+1);
     
    fact[0]=1;
    for(int i=1;i<=N;i++) fact[i]=fact[i-1]*i;
     
    factinv[N]=fact[N].inv();
    for(int i=N;i>=1;i--) factinv[i-1]=factinv[i]*i;
}
/*
mint nCr(int n, int r) {
    if(n>=MOD) return nCr(n%MOD,r%MOD) * nCr(n/MOD,r/MOD);
    return r>n? 0:fact[n]*factinv[n-r]*factinv[r];
}//O(P+log N)
*/
///*
mint nCr(int n,int r){
    if(r>n) return 0;
    mint a=1,b=1;
    for(int i=0;i<r;++i) a*=(n-i);
    for(int i=1;i<=r;++i)b*=i;
    return a/b;
}//O(r)
//*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //LucasInit(1000000);
    int n,m,k;
    cin>>cases;
    while(cases--) {
        cin>>n>>m>>k;
        if(m==1){
            cout<<n<<'\n';
        }
        else{
            cout<<(nCr(n-k*m-1,m-1)*(mint)n/(mint)m).x<<'\n';
        }
    }
}