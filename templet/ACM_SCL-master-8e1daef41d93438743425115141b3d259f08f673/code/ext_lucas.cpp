//模数为合数，需要ext_gcd,ext_crt
//模数质因数只为1次幂素数的积时，不用cal、multiLucas
//否则，还需要pow_mod
//O(log^2 N + k^4*logNlogP + k^4*Plog^3P)
namespace ext_lucas{
    int tot;
    ll prime[20],mo[20],fact[20];
    ll cal(ll n,ll a,ll p) {
        if(!n) return 1;
        ll i,y=n/p,tmp=1;
        for(i=1;i<=p;i++)if(i%a) tmp=tmp*i%p;
        ll ans=pow_mod(tmp,y,p);
        for(i=y*p+1;i<=n;i++)if(i%a) ans=ans*i%p;
        return ans*cal(n/a,a,p)%p;
    }
    ll multiLucas(ll n,ll m,ll a,ll p) {
        ll i,t1,t2,t3,tmp,s=0;
        for(i=n;i;i/=a) s+=i/a;
        for(i=m;i;i/=a) s-=i/a;
        for(i=n-m;i;i/=a) s-=i/a;
        tmp=pow_mod(a,s,p);
        t1=cal(n,a,p),t2=cal(m,a,p),t3=cal(n-m,a,p);
        return tmp*t1%p*Inv(t2,p)%p*Inv(t3,p)%p;
    }
    ll nCm(ll n,ll m,ll p) {
        if(m>n) return 0;
        ll a=1,b=1;
        for(int i=0;i<m;++i) a=a*(n-i)%p;
        for(int i=1;i<=m;++i)b=b*i%p;
        return a*Inv(b,p);
    }
    ll Lucas(ll n,ll m,ll p){
        if(!m) return 1;
        return Lucas(n/p,m/p,p)*nCm(n%p,m%p,p)%p;
    }
    void init(ll p){
        tot=0;
        for(ll i=2;i*i<=p;i++){
            if(p%i==0){
                prime[tot]=i;fact[tot]=1;
                while(p%i==0){p/=i;fact[tot]*=i;}
                tot++;
            }
        }
        if(p>1){fact[tot]=prime[tot]=p;tot++;}
    }
    ll solve(ll n,ll m){
        for(int i=0;i<tot;i++){
            if(prime[i]==fact[i]) mo[i]=Lucas(n,m,prime[i]);
            else mo[i]=multiLucas(n,m,prime[i],fact[i]);
        }
        return ext_crt(tot,fact,mo);
    }
}//先init， 再solve