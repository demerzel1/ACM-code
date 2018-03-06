struct mincostmaxflow {
    struct edge{
        int to,cap,cost,rev;
        edge(){};
        edge(int a,int b,int c,int d):to(a),cap(b),cost(c),rev(d){};
    };
    vector<edge>gra[MAXV];
    int high[MAXV],dist[MAXV];
    int prevv[MAXV],preve[MAXV];
    int flow,mincost,V;
    
    void init(){for(int i=0;i<=V;i++){gra[i].clear();}}
    
    void addedge(int from,int to,int cap,int cost){
        gra[from].push_back(edge(to,cap,cost,(int)gra[to].size()));
        gra[to].push_back(edge(from,0,-cost,(int)gra[from].size()-1));
    }
    void dijk_min_cost_flow(int s,int t,int f){
        mincost=flow=0;
        memset(high, 0, sizeof high);
        while(f>0){
            priority_queue<ii,vector<ii>,greater<ii> >Q;
            memset(dist, 0x3f, sizeof dist);
            dist[s]=0;
            Q.push(ii(0,s));
            while(!Q.empty()){
                ii p=Q.top();Q.pop();
                int v=p.second;
                if(dist[v]<p.first) continue;
                for(int i=0;i<gra[v].size();i++){
                    edge &e=gra[v][i];
                    if(e.cap>0&&dist[e.to]>dist[v]+e.cost+high[v]-high[e.to]){
                        dist[e.to]=dist[v]+e.cost+high[v]-high[e.to];
                        prevv[e.to]=v;preve[e.to]=i;
                        Q.push(ii(dist[e.to],e.to));
                    }
                }
            }
            if(dist[t]==INF){mincost=-1;return;}
        
            for(int v=0;v<V;v++){high[v]+=dist[v];}
        
            int d=f;
            for(int v=t;v!=s;v=prevv[v]){
                d=min(d, gra[prevv[v]][preve[v]].cap);
            }
            f-=d;
            mincost+=d*high[t];flow+=d;
            for(int v=t;v!=s;v=prevv[v]){
                edge &e=gra[prevv[v]][preve[v]];
                e.cap-=d;
                gra[v][e.rev].cap+=d;
            }
        }
    }
}solve;