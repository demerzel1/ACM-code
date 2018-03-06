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
