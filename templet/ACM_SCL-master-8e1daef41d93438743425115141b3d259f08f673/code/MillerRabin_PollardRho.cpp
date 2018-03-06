template<class T>T gcd(T a,T b){
    if(!a)return 1;if(!b)return a;
    if(a<0) a=-a; for (T t;b;t=a%b,a=b,b=t);
    return a;
}
//(2^63-1)下的确定算法
//const ll j32[3]={2,7,61};
//if(n==2||n==7||n==61)return true;
const ll j64[7]={2,325,9375,28178,450775,9780504,1795265022};
//快速幂
bool check(ll a,ll n,ll x){
    ll ret=pow_mod(a,x,n);
    while(x!=n-1&&ret!=n-1&&ret!=1){
        ret=mul_mod(ret,ret,n);
        x<<=1;
    }
    return ((ret==n-1)||(x&1));
}
bool Miller_Rabin(ll n){
    if(n==2||n==3||n==5||n==13||n==19||n==73||
       n==193||n==407521||n==299210837) return true;
    if(n<2||!(n&1)) return false;//偶数
    ll x=n-1;
    while(!(x&1)){x>>=1;}
    for(int i=0;i<7;i++){
        if(!check(j64[i],n,x)) return false;//合数
    }
    return true;
}
ll Pollard_rho(ll x,ll c){
    for(ll i=2,k=2,x0=rand()%x,y=x0;;i++){
        x0=(mul_mod(x0,x0,x)+c)%x;
        ll d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){y=x0;k+=k;}
    }
}

map<ll,ll>fact;//<质因数,count>
void findfac(ll n){
    if(Miller_Rabin(n)){++fact[n];return;}
    ll p=n;
    for(;p>=n;p=Pollard_rho(p,rand()%(n-1)+1));
    findfac(p); findfac(n/p);
}