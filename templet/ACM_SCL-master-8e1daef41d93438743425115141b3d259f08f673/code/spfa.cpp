typedef int T;
int cnt[MAXN];
bool vis[MAXN];
T dis[MAXN];
bool spfa(int n,int st){
    deque<int>Q;
    memset(dis,0x3f,sizeof dis);dis[st]=0;
    memset(vis,0,sizeof vis);
    memset(cnt,0,sizeof cnt);cnt[st]=1;

    Q.push_back(st);
    while(!Q.empty()) {
        int u=Q.front(); Q.pop_front();
        for(int i=head[u];~i;i=edge[i].next){
            int v=edge[i].to;
            T w=edge[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    if(++cnt[v]>=n) return 0;//负环
                    if(!Q.empty()&&dis[Q.front()]>dis[v])//SLF
                        Q.push_front(v);
                    else
                        Q.push_back(v);
                    vis[v]=1;
                }           
            }
        }
        vis[u]=0;
    }
    return 1;
}