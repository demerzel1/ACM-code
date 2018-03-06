//n¸ömi»¥ÖÊ

const ll maxn = 105;
ll a[maxn], m[maxn], n;

int exgcd(int a,int b,int &x,int &y) {
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}


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


