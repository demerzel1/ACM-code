template<typename T> struct BIT{//[1,N]
#define lowbit(x) (x&-x)
    T data[MAXN];
    void clear(){memset(data,0,sizeof(data));}
    void add(int x,T w){for(;x<MAXN;x+=lowbit(x))data[x]+=w;}
    T pre_sum(int x){//[1,x]
        T r=0;
        for(;x;x-=lowbit(x))r+=data[x];
        return r;
    }
    T range_sum(int l,int r){return pre_sum(r)-pre_sum(l-1);}//[l,r]
};
template<typename T> struct lazyBIT{//[1,N]
    BIT<T>b1,b2;
    void clear(){b1.clear(),b2.clear();}
    void range_add(int l,int r,T w){
        b1.add(l,w),b1.add(r,-w);
        b2.add(l,w*(1-l)),b2.add(r,w*r);
    }
    T pre_sum(int x){return b1.pre_sum(x)*(T)x+b2.pre_sum(x);}
    T range_sum(int l,int r){return pre_sum(r)-pre_sum(l-1);}
};