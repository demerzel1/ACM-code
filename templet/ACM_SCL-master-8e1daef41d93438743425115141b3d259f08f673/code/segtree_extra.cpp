template<class T> struct Segtree{
#define ls (o<<1)
#define rs (o<<1)|1
    T lazy[MAXN<<2],mul[MAXN<<2],Set[MAXN<<2];
    T data[MAXN<<2][3];
    void pushup(int o){
        for(int i=0;i<3;i++){
            data[o][i]=data[ls][i]+data[rs][i];
        }
    }
    void setlazy(int o,int t,T m,T a){
        data[o][2]=m*m*m*data[o][2]+m*m*a*data[o][1]*3
                  +a*a*m*data[o][0]*3+a*a*a*t;
        data[o][1]=m*m*data[o][1]+a*m*data[o][0]*2+a*a*t;
        data[o][0]=data[o][0]*m+a*t;
        mul[o]=mul[o]*m;
        lazy[o]=lazy[o]*m+a;
    }
    void setset(int o,int t,T a){
        data[o][2]=a*a*a*t;
        data[o][1]=a*a*t;
        data[o][0]=a*t;
        Set[o]=a;
        mul[o]=1;lazy[o]=0;
    }
    void pushdown(int o,int m){
        if(Set[o].get()!=0){
            setset(ls,m-(m>>1),Set[o]);
            setset(rs,m>>1,Set[o]);
            Set[o]=0;
        }
        if(mul[o].get()!=1||lazy[o].get()!=0){
            setlazy(ls,m-(m>>1),mul[o],lazy[o]);
            setlazy(rs,m>>1,mul[o],lazy[o]);
            mul[o]=1;lazy[o]=0;
        }
    }
    void build_tree(int o,int l,int r){
        lazy[o]=Set[o]=0;mul[o]=1;
        if (l==r){
            for(int j=0;j<3;j++) data[o][j]=0;
            return;
        }
        int mid=(l+r)>>1;
        build_tree(ls,l,mid);
        build_tree(rs,mid+1,r);
        pushup(o);
    }
    void update(int o,int l,int r,int x,int y,T m,T c,bool flag){
        if(x<=l&&r<=y){
            if(flag){
                setset(o,r-l+1,c);
            }
            else{
                setlazy(o,r-l+1,m,c);
            }
            return;
        }
        pushdown(o,r-l+1);
        int mid=(l+r)>>1;
        if(x<=mid) update(ls,l,mid,x,y,m,c,flag);
        if(y>mid)  update(rs,mid+1,r,x,y,m,c,flag);
        pushup(o);
    }
    T query(int o,int l,int r,int x,int y,int type){
        if(x<=l&&r<=y){
            return data[o][type];
        }
        pushdown(o,r-l+1);
        int mid=(l+r)>>1;
        if(y<=mid)  return query(ls,l,mid,x,y,type);
        if(x>mid)   return query(rs,mid+1,r,x,y,type);
        return query(ls,l,mid,x,y,type)+query(rs,mid+1,r,x,y,type);
    }
};