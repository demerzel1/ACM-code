vector<pii> g[maxn];
int v[maxn];
int dis[maxn];


void prim() {
    memset(v,0,sizeof(v));
    for(int i=1; i<=n; i++) {
        dis[i]=INF;
    }
    dis[1]=0;
    int ans=0;
    for(int i=1; i<=n; i++) {
        int mark=-1;
        for(int j=1; j<=n; j++) {
            if(!v[j]) {
                if(mark==-1)
                    mark=j;
                else if(dis[j]<dis[mark])
                    mark=j;
            }
        }
        if(mark==-1)
            break;
        v[mark]=1;
        ans+=dis[mark];
        for(int j=0; j<g[mark].size(); i++) {
            if(!v[g[mark][j].first]) {
                int x=g[mark][j].first;
                dis[x]=min(dis[x],g[mark][j].second);
            }
        }
    }
    return ans;
}