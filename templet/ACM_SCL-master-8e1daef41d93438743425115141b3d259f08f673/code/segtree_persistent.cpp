int root[MAXN];
template<typename T>
struct PSegtree{
    int tot;
    struct node{
        int l,r;
        T sum,lazy;
    }t[MAXN<<5];
    void clear(){
        tot=0;
        memset(&t[0],0,sizeof(node));
    }
    void addnode(int &o){
        t[++tot]=t[o]; o=tot;
    }
    void pushup(int o){
        t[o].sum=t[t[o].l].sum+t[t[o].r].sum;
    }
    void build(int &o,int l,int r){
        addnode(o);
        if(l==r){
            t[o].sum=num[l];
            return;
        }
        int mid=(l+r)>>1;
        build(t[o].l,l,mid); build(t[o].r,mid+1,r);
        pushup(o);
    }
    void update(int &o,int l,int r,int x,int y,T v){
        addnode(o);
        t[o].sum+=v*(min(r,y)-max(l,x)+1);
        if(x<=l && r<=y){
            t[o].lazy+=v;
            return;
        }
        int mid=(l+r)>>1;
        if(x<=mid) update(t[o].l,l,mid,x,y,v);
        if(y>mid) update(t[o].r,mid+1,r,x,y,v);
    }
    T query(int &o,int l,int r,int x,int y){
        if(x<=l && r<=y) return t[o].sum;
        T ret=t[o].lazy*(min(r,y)-max(l,x)+1);
        int mid=(l+r)>>1;
        if(x<=mid) ret+=query(t[o].l,l,mid,x,y);
        if(y>mid) ret+=query(t[o].r,mid+1,r,x,y);
        return ret;
    }
};