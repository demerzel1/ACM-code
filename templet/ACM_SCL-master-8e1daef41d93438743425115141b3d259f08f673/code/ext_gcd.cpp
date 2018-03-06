ll ext_gcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1;y=0;return a;}
    ll d=ext_gcd(b,a%b,y,x);
    y-=a/b*x; return d;
}
ll Inv(ll x,ll p){
    ll u,v; ext_gcd(x,p,u,v);
    return u<0?u+p:u;
}//模质数适用