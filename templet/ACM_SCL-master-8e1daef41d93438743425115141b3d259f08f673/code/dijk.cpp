typedef int T;
typedef pair<T,int> ii;
bool vis[MAXN];
T dis[MAXN];
void dijk(int st){
    ii u(0,st);
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));dis[st]=0;
    priority_queue<ii,vector<ii>,greater<ii> >Q;
    Q.push(u);
    while(!Q.empty()) {
        int u=Q.top().second;Q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        //if(u==ed) return;
        for(int i=head[u];~i;i=edge[i].next){
            int v=edge[i].to;
            T w=edge[i].w;
            if(!vis[v]&&dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                Q.push(ii(dis[v],v));
            }
        }
    }
}