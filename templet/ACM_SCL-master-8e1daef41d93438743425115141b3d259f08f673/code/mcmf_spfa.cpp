const int INF=0x3f3f3f3f;
struct mcmf{
    int flow,mincost,V;
    struct edge{
        int to,cap,cost,rev;
        edge(){};
        edge(int a,int b,int c,int d):to(a),cap(b),cost(c),rev(d){};
    };
    vector<edge>gra[MAXN];
    int dist[MAXN];
    int aug[MAXN];
    bool in[MAXN];
    ii prev[MAXN];

    void init(){for(int i=0;i<=V;i++){gra[i].clear();}}

    void addedge(int from,int to,int cap,int cost){
        gra[from].emplace_back(edge(to,cap,cost,(int)gra[to].size()));
        gra[to].emplace_back(edge(from,0,-cost,(int)gra[from].size()-1));
    }
    void mcmf_spfa(int S,int T){
        flow=mincost=0;
        for(;;){
            int u,v;queue<int>Q;
            memset(dist,0x3f,sizeof dist);dist[S]=0;
            memset(in,0,sizeof in); in[S]=1;
            Q.push(S); aug[S]=INF;
            while(!Q.empty()){
                u=Q.front();Q.pop();in[u]=0;
                for(int i=0;i<gra[u].size();i++){
                    edge &e=gra[u][i]; v=e.to;
                    if(e.cap>0&&dist[v]>dist[u]+e.cost){
                        dist[v]=dist[u]+e.cost;
                        prev[v]=ii(u,i);
                        aug[v] = min(aug[u], e.cap);
                        if(!in[v]){ in[v]=1; Q.push(v);}
                    }
                }
            }
            if(dist[T]==INF) return;
            mincost+=dist[T]*aug[T];
            flow+=aug[T];
            for(v=T;v!=S;v=prev[v].first){
                edge &e=gra[prev[v].first][prev[v].second];
                e.cap-=aug[T];
                gra[v][e.rev].cap+=aug[T];
            }
        }
    }
}solve;