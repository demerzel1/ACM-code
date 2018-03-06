template<typename T,typename U=less<T> > struct d_que{
    struct node{
        T val;
        int lim;
        node(T v=0,int li=0):val(v),lim(li){}
    };
    inline bool les(const T& a,const T& b,U cmp=U()){
        return cmp(a,b);
    }
    int s;//队列中有s个元素
    int cnt;//当前是第cnt个元素
    deque<node>Q;
    
    d_que(){Q.clear();s=cnt=0;}
    void init(int _s){
        Q.clear();s=_s;cnt=0;
    }
    void push(T v){
        while(!Q.empty()&&les(Q.back().val, v)){
            Q.pop_back();
        }
        Q.push_back(node(v,cnt++));
    }
    T top(){
        while(!Q.empty()&&Q.front().lim<cnt-s){
            Q.pop_front();
        }
        assert(!Q.empty());
        return Q.front().val;
    }//返回 (now-s,now] 的最大值
};