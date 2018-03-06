//模质数时适用,需要mint
vector<mint> fact,factinv;
void LucasInit(int N) {
    N=min(N,MOD-1); fact.resize(N+1);factinv.resize(N+1);
    fact[0]=1;
    for(int i=1;i<=N;i++) fact[i]=fact[i-1]*i;
    factinv[N]=fact[N].inv();
    for(int i=N;i>=1;i--) factinv[i-1]=factinv[i]*i;
}
mint nCm(int n, int m) {
    if(n>=MOD) return nCm(n%MOD,m%MOD) * nCm(n/MOD,m/MOD);
    return m>n? 0:fact[n]*factinv[n-m]*factinv[m];
}//O(P+log N),先调用LucasInit
mint C(int n,int m){
    if(m>n) return 0;
    mint a=1,b=1;
    for(int i=0;i<m;++i) a*=(n-i);
    for(int i=1;i<=m;++i)b*=i;
    return a/b;
}//O(m)