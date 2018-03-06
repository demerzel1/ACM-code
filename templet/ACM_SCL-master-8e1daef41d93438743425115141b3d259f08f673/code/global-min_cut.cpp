//V*E+V*V*logV
int n,dis[MAXN],vis[MAXN];
int phase(int &s,int &t,int cnt){
    int x=0;
    for(int i=1;i<=n;i++){
        if(vis[i]<cnt)
            dis[i]=0,x++;
    }
    priority_queue<ii>q;
    q.push(ii(0,s));
    while(!q.empty() && x--) {
        int u=q.top().second;q.pop();
        while(!q.empty() && vis[u]==cnt){
            u=q.top().second;q.pop();
        }
        s=t;t=u;vis[t]=cnt;
        for(int i=head[t];~i;i=edge[i].next){
            int v=edge[i].to;
            if(vis[v]!=cnt) {
                dis[v]+=edge[i].w;
                q.push(ii(dis[v],v));
            }
        }
    }
    return dis[t];
}
int min_cut() {
    int i,t,u,s=1,r=INF;
    memset(vis, 0, sizeof(vis));
    for(i=1;i<n;i++){
        r=min(r,phase(s,t,i));
        if(!r)return 0;
        vis[t]=n; u=head[t];
        while(~u) {
            edge[u^1].to=s;
            swap(edge[u].next,head[s]);
            swap(head[s],u);
        }
    }
    return r==INF?0:r;
}


//V*V*V
int g[MAXN][MAXN];
int dis[MAXN],v[MAXN];
bool vis[MAXN];
int min_cut(int n) {
    int i,j,res=INF;
    for(i=0;i<n;i++)v[i]=i;
    while(n>1){
        int maxp=1,prev=0;
        for(i=1;i<n;i++){
            dis[v[i]]=g[v[0]][v[i]];
            if (dis[v[i]]>dis[v[maxp]]) maxp=i;
        }
        memset(vis,0,sizeof(vis)); vis[v[0]]=1;
        for(i=1;i<n;i++){
            if(i==n-1){
                res=min(res,dis[v[maxp]]);
                for(j=0;j<n;j++){
                    g[v[prev]][v[j]]+=g[v[j]][v[maxp]];
                    g[v[j]][v[prev]] =g[v[prev]][v[j]];
                }v[maxp]=v[--n];
            }
            vis[v[maxp]]=1; prev=maxp; maxp=-1;
            for (j=1;j<n;j++)
                if(!vis[v[j]]){
                    dis[v[j]]+=g[v[prev]][v[j]];
                    if(maxp==-1 || dis[v[maxp]]<dis[v[j]])
                        maxp=j;
                }
        }
    }
    return res==INF?0:res;
}