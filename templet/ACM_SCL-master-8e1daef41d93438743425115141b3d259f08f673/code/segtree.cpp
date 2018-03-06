template<class T> struct Segtree{
#define ls (o<<1)
#define rs (o<<1)|1
    T lazy[MAXN<<2];
    T data[MAXN<<2];
    void pushup(int o){
        data[o]=data[ls]+data[rs];
    }  
    void setlazy(int o,int t,T v){
        lazy[o]+=v;
        data[o]+=v*t;
    }
    void pushdown(int o,int m){
        if(lazy[o]){
            setlazy(ls,m-(m>>1),lazy[o]);
            setlazy(rs,m>>1,lazy[o]);
            lazy[o]=0;
        }
    }
    void build(int o,int l,int r){
        lazy[o]=0;
        if(l==r){
            data[o]=0;
            return;
        }
        int mid=(l+r)>>1;
        build(ls,l,mid);build(rs,mid+1,r);
        pushup(o);
    }
    void update(int o,int l,int r,int x,int y,T v){
        if(x<=l&&r<=y){
            setlazy(o,r-l+1,v);
            return;
        }
        pushdown(o,r-l+1);
        int mid=(l+r)>>1;
        if(x<=mid) update(ls,l,mid,x,y,v);
        if(y>mid)  update(rs,mid+1,r,x,y,v);
        pushup(o);
    }
    T query(int o,int l,int r,int x,int y){
        if(x<=l&&r<=y){
            return data[o];
        }
        pushdown(o,r-l+1);
        int mid=(l+r)>>1;
        if(y<=mid) return query(ls,l,mid,x,y);
        if(x>mid)  return query(rs,mid+1,r,x,y);
        return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);
    }
};