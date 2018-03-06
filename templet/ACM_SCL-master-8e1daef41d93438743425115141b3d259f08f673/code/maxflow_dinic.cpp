template<class T>struct Dinic{
    struct edge{
        int v,rev;T cap;
        edge(){}
        edge(int a,T b,int c):v(a),cap(b),rev(c){}
    };vector<edge>g[MAXN];
    int d[MAXN],q[MAXN],cur[MAXN],s,t;
    void clear(int n){for(int i=0;i<=n;i++)g[i].clear();}
    void addedge(int u,int v,T c){
        g[u].emplace_back(v,c,g[v].size());
        g[v].emplace_back(u,0,g[u].size()-1);
    }
    bool bfs(){
        memset(d,-1,sizeof(d));
        int hd=0,tl=0;
        d[s]=0;q[tl++]=s;
        while(tl>hd){
            int u=q[hd++];
            for(const auto&e:g[u]){
                if(~d[e.v] || !e.cap)continue;
                d[e.v]=d[u]+1,q[tl++]=e.v;
                if(e.v==t)return 1;
            }
        }
        return 0;
    }
    T dfs(int u,T a){
        if(u==t || !a)return a;
        T f=0,z=0;
        for(int &i=cur[u];i<g[u].size();i++){
            auto &e=g[u][i];
            if(d[e.v]==d[u]+1 && (z=dfs(e.v,min(a,e.cap)))){
                e.cap-=z,g[e.v][e.rev].cap+=z;
                f+=z,a-=z;
            }
            if(!a)break;
        }
        return f;
    }
    T dinic(int a,int b){
        s=a,t=b;T r=0;
        for(;bfs();memset(cur,0,sizeof(cur)))r+=dfs(s,INF);
        return r;
    }
};