namespace Rabin{
    const static ll P=127;
    const static int M1=524287;
    const static int M2=INT_MAX;
    uint b1[MAXN],b2[MAXN];
    inline uint mo(ll o,int M,int T){
        o=(o&M)+(o>>T); return o<M?o:o-M;
    }
    void init(){
        b1[0]=b2[0]=1;
        for(int i=1;i<MAXN;i++){
            b1[i]=mo(P*b1[i-1],M1,19);
            b2[i]=mo(P*b2[i-1],M2,31);
        }
    }
    struct Karp{
        uint h1[MAXN],h2[MAXN];
        Karp(char *s,int len){
            h1[0]=h2[0]=1;
            for(int i=1;i<=len;i++){
                h1[i]=mo(P*h1[i-1],M1,19)+s[i-1];
                if(h1[i]>=M1)h1[i]-=M1;
                h2[i]=mo(P*h2[i-1],M2,31)+s[i-1];
                if(h2[i]>=M2)h2[i]-=M2;
            }
        }
        ll ha(int l,int r){
            ll t1=h1[r],t2=h2[r];
            t1-=mo((ll)h1[l]*b1[r-l],M1,19);
            t2-=mo((ll)h2[l]*b2[r-l],M2,31);
            if(t1<0)t1+=M1; if(t2<0)t2+=M2;
            return t1<<31|t2;
        }//[l,r)
    };
}