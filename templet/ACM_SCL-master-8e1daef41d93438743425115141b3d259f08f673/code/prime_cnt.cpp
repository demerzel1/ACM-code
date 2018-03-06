namespace prime_cnt {
    const int N = 6000002;
    bool np[N];
    int p[N],pi[N];
    int getprime(){
        int cnt=0;
        np[0]=np[1]=true;
        pi[0]=pi[1]=0;
        for(int i=2; i<N; i++){
            if(!np[i]) p[++cnt]=i;
            for(int j=1;j<=cnt && i*p[j]<N; ++j) np[i*p[j]]=true;
            pi[i]=cnt;
        }return cnt;
    }
    const int M = 7;
    const int PM = 2*3*5*7*11*13*17;
    int phi[PM+1][M+1],sz[M+1];
    void init(){
        getprime(); sz[0]=1;
        for(int i=0;i<=PM;++i)  phi[i][0]=i;
        for(int i=1;i<=M;++i){
            sz[i]=p[i]*sz[i-1];
            for(int j=1;j<=PM;++j){
                phi[j][i]=phi[j][i-1]-phi[j/p[i]][i-1];
            }
        }
    }
    int sqrt2(ll x){
        ll r = (ll)sqrt(x-0.1);
        while(r*r<=x)   ++r;
        return int(r-1);
    }
    int sqrt3(ll x){
        ll r = (ll)cbrt(x-0.1);
        while(r*r*r<=x)   ++r;
        return int(r-1);
    }
    ll getphi(ll x,int s){
        if(s == 0)  return x;
        if(s <= M)  return phi[x%sz[s]][s]+(x/sz[s])*phi[sz[s]][s];
        if(x <= p[s]*p[s])   return pi[x]-s+1;
        if(x <= p[s]*p[s]*p[s] && x< N){
            int s2x = pi[sqrt2(x)];
            ll ans = pi[x]-(s2x+s-2)*(s2x-s+1)/2;
            
            for(int i=s+1;i<=s2x;++i) ans+=pi[x/p[i]];
            return ans;
        }
        return getphi(x,s-1)-getphi(x/p[s],s-1);
    }
    ll getpi(ll x){
        if(x < N)   return pi[x];
        ll ans = getphi(x,pi[sqrt3(x)])+pi[sqrt3(x)]-1;
        for(int i=pi[sqrt3(x)]+1,ed=pi[sqrt2(x)];i<=ed;++i){
            ans -= getpi(x/p[i])-i+1;
        }
        return ans;
    }//[1,x]的质数个数
}//先init(),O(n^{2/3})