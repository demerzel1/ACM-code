//边双连通分量：求出所有的桥以后，把桥边删除
//Gra_base
typedef pair<int,int>ii;
vector<int>cut;
vector<ii>bridge;
vector<vector<ii> >bcc;//点双联通分量
stack<ii>s;//
int dfn[MAXN],low[MAXN],stamp;
void tarjan(int u,int pre){
    int part=(pre==-1?0:1);
    dfn[u]=low[u]=++stamp;
    for(int i=gra.head[u]; ~i; i=gra.edge[i].next){
        int v=gra.edge[i].to;
        ii f=make_pair(min(u,v),max(u,v));
        if(dfn[v]==-1){
            s.push(f);//
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<=low[v]){
                if(++part==2){
                    cut.push_back(u);
                }//割点
                if(dfn[u]<low[v]){
                    bridge.push_back(f);
                }//桥
                
                ///*
                vector<ii> t;
                do{
                    t.push_back(s.top());
                    s.pop();
                }while(t.back()!=f);
                bcc.push_back(t);
                //*/点双联通分量
            }
        }
        else if(v!=pre&& dfn[v]<dfn[u]){
            s.push(f);//
            low[u]=min(low[u],dfn[v]);
        }
    }
}
void solve(int n){
    stamp=0;
    bcc.clear();//
    cut.clear();
    bridge.clear();
    while(!s.empty()) s.pop();//
    memset(dfn,-1,sizeof(dfn));
    
    for(int i=0;i<n;i++) if(dfn[i]==-1)
        tarjan(i,-1);
}

//uni-find
void build_tree(int n){
    tre.clear();
    init();//uni-find
    
    solve(n);
    for(const auto&u:bcc) if(u.size()>1)
        for(const auto&v:u)
            join(v.first,v.second);
    
    for(const auto&v:bridge){
        int a=Find(v.first);
        int b=Find(v.second);
        tre.addedge(a,b);
        tre.addedge(b,a);
    }
}//缩点建树
int getID(int v){return Find(v);}