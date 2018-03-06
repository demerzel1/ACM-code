template<class T>inline T gcd(T a,T b){
    if(!a)return 1;if(!b)return a;
    if(a<0) a=-a; for(T t;b;t=a%b,a=b,b=t);
    return a;
}