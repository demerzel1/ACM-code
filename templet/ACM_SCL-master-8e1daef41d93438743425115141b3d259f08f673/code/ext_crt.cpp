//ext_gcd
ll ext_crt(const vector<ll>&m,const vector<ll>&a){
    ll M=m[0],ret=a[0],x,y,d;
    for(int i=1;i<m.size();++i){
        d=ext_gcd(M,m[i],x,y);
        if((a[i]-ret)%d) return -1;
        x=(a[i]-ret)/d*x%(m[i]/d);
        ret+=x*M;
        M=M/d*m[i];
        ret%=M;
    }
    return (ret%M+M)%M;
}//x=a(mod m)