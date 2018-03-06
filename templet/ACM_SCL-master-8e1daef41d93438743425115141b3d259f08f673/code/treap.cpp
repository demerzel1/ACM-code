int ran(){
    static int g=1;
    return g=(g>>1)^(-(g&1u)&0xD0000001u);
}
template<typename T,typename U=less<T> >struct Treap{
    int size,root;
    struct node{
        T key;
        int s,fx,ls,rs;
        node(){}
        node(const T&k):s(1),key(k),fx(ran()){ls=rs=-1;}
    }q[MAXN];
    vector<int>rec;
    Treap():root(-1){}
    int sz(int o){return ~o?q[o].s:0;}
    void up(node &o){o.s=sz(o.ls)+sz(o.rs)+1;}
    bool cmp(const T&a,const T&b,U les=U()){
        return les(a,b);
    }
    int add(const T&k){
        if(rec.empty()){
            q[size++]=node(k); return size-1;
        }else{
            int o=rec.back();rec.pop_back();
            q[o]=node(k); return o;
        }
    }
    void del(int o){q[o].s=-1,rec.emplace_back(o);}
    int merge(int A,int B){
        if(A==-1)return B;if(B==-1)return A;
        node &a=q[A],&b=q[B];
        if(a.fx<b.fx){
            a.rs=merge(a.rs,B); up(a); return A;
        }else{
            b.ls=merge(A,b.ls); up(b); return B;
        }
    }
    void split_k(int _o,int k,int &x,int &y){
        if(_o==-1){x=y=-1;return;}
        node &o=q[_o];
        if(sz(o.ls)>=k)
            y=_o,split_k(o.ls,k,x,o.ls);
        else
            x=_o,split_k(o.rs,k-sz(o.ls)-1,o.rs,y);
        up(o);
    }
    void split_v(int _o,const T&k,int &x,int &y){
        if(_o==-1){x=y=-1;return;}
        node &o=q[_o];
        if(cmp(k,o.key))
            y=_o,split_v(o.ls,k,x,o.ls);
        else
            x=_o,split_v(o.rs,k,o.rs,y);
        up(o);
    }
    int kth_q(const T&k){
        int r=0,o=root;
        while(~o){
            if(cmp(q[o].key,k))
                r+=sz(q[o].ls)+1,o=q[o].rs;
            else o=q[o].ls;
        }return r;
    }
    void insert(const T&k){
        int x=-1,y=-1,kt=kth_q(k);
        split_k(root,kt,x,y);
        root=merge(merge(x,add(k)),y);
    }
    void erase(const T&k){
        int x=-1,y=-1,z=-1,kt=kth_q(k);
        split_k(root,kt,x,z);split_k(z,1,z,y);
        root=merge(x,y); del(z);
    }
    node& q_kth(int o,int k){
        for(;;){
            int lsz=sz(q[o].ls);
            if(k==lsz+1)return q[o];
            else if(k<=lsz)o=q[o].ls;
            else k-=lsz+1,o=q[o].rs;
        }
    }
    node& lower_bound(const T&k){
        int x=-1,y=-1;
        split_v(root,k-1,x,y);
        node& r=q_kth(x,sz(x));
        root=merge(x,y);return r;
    }
    node& upper_bound(const T&k){
        int x=-1,y=-1;
        split_v(root,k,x,y);
        node& r=q_kth(y,1);
        root=merge(x,y);return r;
    }
};