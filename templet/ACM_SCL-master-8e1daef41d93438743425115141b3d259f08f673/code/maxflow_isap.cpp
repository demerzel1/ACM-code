template<class T>struct ISAP{
    struct edge{
        int v,rev;T cap;
        edge(){}
        edge(int a,T b,int c):v(a),cap(b),rev(c){}
    };vector<edge>g[MAXN];
    int d[MAXN],gap[MAXN],q[MAXN],cur[MAXN],s,t,n;
    void clear(int _){n=_;for(int i=0;i<=n;i++)g[i].clear();}
    void addedge(int u,int v,T c){
        g[u].emplace_back(v,c,g[v].size());
        g[v].emplace_back(u,c,g[u].size()-1);
    }
    bool bfs(){
        memset(gap,0,sizeof(gap)); memset(d,-1,sizeof(d));
        int u,v,hd=0,tl=0;  d[t]=0,q[tl++]=t;
        while(tl>hd) {
            u=q[hd++];
            for(const auto&e:g[u]){
                v=e.v; if(~d[v])continue;
                d[v]=d[u]+1,gap[d[v]]++,q[tl++]=v;
            }
        }return ~d[s];
    }
    T dfs(int u,T f,int s,int t){
        if(u==t)return f;
        T r=0;
        for(int i=cur[u];i<g[u].size();i++){
            auto &e=g[u][i];
            if(d[u]==d[e.v]+1){
                T tmp=dfs(e.v,min(e.cap,f-r),s,t);
                e.cap-=tmp,g[e.v][e.rev].cap+=tmp,cur[u]=i;
                if((r+=tmp)==f)return f;
            }
        }cur[u]=0;
        if(!(--gap[d[u]]))d[s]=n;
        gap[++d[u]]++; return r;
    }
    T isap(int a,int b){
        s=a,t=b; T ans=0;
        if(!bfs())return 0;
        memset(cur,0,sizeof(cur));
        while(d[s]<n)ans+=dfs(s,INF,s,t);
        return ans;
    }
};