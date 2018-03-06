template<typename T> struct Kruskal{
    struct edge{
        int u,v;
        T c;
        edge(){}
        edge(int x,int y,T z):u(x),v(y),c(z){}
    };
    vector<edge>e;
    void clear(){e.clear();}
    void addedge(int u,int v,T c){e.emplace_back(edge(u,v,c));}
    T query(int n){
        Dsu dsu;int cnt=0;T tot=0;
        sort(e.begin(),e.end(),[&](const edge&e1,const edge&e2){
            return e1.c<e2.c;
        });
        for(const auto&t:e){
            if(dsu.join(t.u,t.v)){
                ++cnt;tot+=t.c;
            }
            if(cnt+1==n) break;
        }
        return tot;
    }
};