ll mul_mod(ll a,ll b,ll p) {
    if (p<=1e9) return a*b%p;
    else if (p<=1e12)
        return (((a*(b>>20)%p)<<20)+(a*(b&((1<<20)-1))))%p;
    else{
        ll d=(ll)floor(a*(long double)b/p+0.5);
        ll r=(a*b-d*p)%p; if (r<0) r+=p;
        return r;
    }
}//a,b<p
ll pow_mod(ll a,ll k,ll p) {
    ll r=1;a%=p;
    for(;k;k>>=1,a=mul_mod(a,a,p)) if(k&1) r=mul_mod(r,a,p);
    return r;
}