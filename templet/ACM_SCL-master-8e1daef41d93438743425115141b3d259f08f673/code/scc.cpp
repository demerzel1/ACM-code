int id[MAXN],dfn[MAXN],low[MAXN],stamp;
stack<int>s;
vector<vector<int> >scc;
void scc_dfs(int u) {
    dfn[u]=stamp++;
    low[u]=dfn[u];
    s.push(u);
    for(int i=gra.head[u];~i;i=gra.edge[i].next){
        int v=gra.edge[i].to;
        if(dfn[v]==-1){
            scc_dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(dfn[v]!=-2){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if (low[u]==dfn[u]) {
        vector<int> t;
        do {
            int w=s.top(); s.pop();
            id[w]=scc.size();
            t.push_back(w);
            dfn[w]=-2;
        }while(t.back()!=u);
        scc.push_back(t);
    }
}
int solve(int n) {
    stamp=0;
    scc.clear();
    while (!s.empty()) s.pop();
    memset(dfn,-1,sizeof(dfn));
    for (int i=0; i<n; i++) if(dfn[i]==-1) scc_dfs(i);
    return scc.size();
}