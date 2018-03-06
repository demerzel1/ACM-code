template<typename T,typename U=less<T>> struct heap{
    int sz,root;
    struct node{
        T key;
        int son,sib;
        node(){}
        node(const T&k):key(k),son(-1),sib(-1){}
        void ins(node &o,int _o){if(~son)o.sib=son;son=_o;}
    }q[MAXN];
    vector<int>rec;
    heap():root(-1){}
    int add(const T&k){
        if(rec.empty()){
            q[sz++]=node(k); return sz-1;
        }else{
            int o=rec.back();rec.pop_back();
            q[o]=node(k); return o;
        }
    }
    void del(int o){rec.emplace_back(o);}
    inline bool cmp(const T&a,const T&b,U les=U()){
        return les(a,b);
    }
    int Merge(int A,int B){
        if(A==-1)return B; if(B==-1)return A;
        node &a=q[A],&b=q[B];
        if(cmp(b.key,a.key)){
            a.ins(b,B); return A;
        }else{
            b.ins(a,A); return B;
        }
    }
    int TwoPassMerge(int A) {
        if(A==-1 || q[A].sib==-1)return A;
        else{
            int B=q[A].sib;q[A].sib=-1;
            int C=q[B].sib;q[B].sib=-1;
            return Merge(Merge(A,B),TwoPassMerge(C));
        }
    }
    void clear(){root=-1;sz=0;rec.clear();}
    int size(){return sz-rec.size();}
    bool empty(){return root==-1;}
    T top(){return q[root].key;}
    void push(const T&k){root=Merge(root,add(k));}
    void pop(){
        if(!empty()){
            int o=root;
            root=TwoPassMerge(q[o].son);
            del(o);
        }
    }
};