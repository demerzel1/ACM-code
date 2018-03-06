//Miller_Rabin
namespace SQUFOF{
#define _sqrt(x) (floor(sqrt(x)+0.5))
    inline bool checkSqr(uint x,uint& t){
        uint f=x&0xf;
        if(f<=9 && (f<2||f==4||f==9)){
            t=_sqrt(1.0*x); return t*t==x;
        }return false;
    }
    uint gao(ull n){
        uint sqrt_n=_sqrt(1.0*n),sqrt_qi;
        uint p1=sqrt_n,q2=1,q1=n-(ull)p1*p1;
        uint b,p,q,step=10000;
        if(!q1) return p1;
        while(!checkSqr(q1,sqrt_qi)){
            b=(sqrt_n+p1)/q1;
            p=b*q1-p1;
            q=q2+b*(p1-p);
            p1=p;q2=q1;q1=q;
        }
        b=(sqrt_n-p1)/sqrt_qi;
        p1=b*sqrt_qi+p;
        q2=sqrt_qi; q1=(n-(ull)p1*p1)/q2;
        p=p1; p1=0;
        while(p!=p1&&step--){
            p1=p; b=(sqrt_n+p1)/q1;
            p=b*q1-p1;
            q=q2+b*(p1-p);
            q2=q1; q1=q;
        }
        return p;
    }
    uint getfac(ull n){
        uint t=0;
        for(uint k=1;t<2;k++)
            t=gcd((ull)gao(k*n),n);
        return t;
    }
    void findfac(ull n){
        if(Miller_Rabin(n)){ans=min(ans,n);return;}
        uint r=getfac(n);
        findfac(r);findfac(n/r);
    }
}