int Inv(ll x,int p){
    int a=p,b=x%p,u=0,v=1,t;
    while(b) {
        t=a/b;
        a-=t*b; swap(a,b);
        u-=t*v; swap(u,v);
    }
    return u<0?u+p:u;
}//x与p互质