typedef int T;
struct Edge {
    int to,next;
    T cap;
    Edge(){}
    Edge(int a,int b,T c):to(a),next(b),cap(c){}
}edge[MAXM<<1];
int tot,head[MAXN];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,T w) {
    edge[tot]=Edge(v,head[u],w);
    head[u]=tot++;
    edge[tot]=Edge(u,head[v],0);//双向边改成w
    head[v]=tot++;
}
int dis[MAXN],cur[MAXN],gap[MAXN],pre[MAXN];
bool bfs(int s,int t){// 逆向BFS
    memset(gap,0,sizeof(gap));
    memset(dis,-1,sizeof(dis));
    queue<int>Q;int i,u,v;
    Q.push(t);dis[t]=0;
    while(!Q.empty()) {
        u=Q.front();Q.pop();
        for(i=head[u];~i;i=edge[i].next){
            v=edge[i].to;
            if(~dis[v])continue;
            dis[v]=dis[u]+1;
            gap[dis[v]]++;
            Q.push(v);
        }
    }
    return ~dis[s];
}
T isap(int n,int s,int t){//源，汇
    if(!bfs(s,t))return 0;
    int i,u=s;T ans=0;
    copy(head,head+n+1,cur);
    while(dis[s]<n){
        if(u==t){
            T aug=INF;
            for(i=s;i!=t;i=edge[cur[i]].to){
                aug=min(aug,edge[cur[i]].cap);
            }
            for(i=s;i!=t;i=edge[cur[i]].to){
                edge[cur[i]].cap-=aug;
                edge[cur[i]^1].cap+=aug;
            }
            ans+=aug;u=s;
        }
        for(i=cur[u];~i;i=edge[i].next){
            Edge &e=edge[i];
            if(e.cap>0 && dis[u]==dis[e.to]+1){
                cur[u]=i;pre[e.to]=i^1;
                u=e.to;break;
            }
        }
        if(~i)continue;
        if(--gap[dis[u]]==0)break;
        cur[u]=head[u];
        int mi=n;
        for(i=head[u];~i;i=edge[i].next){
            Edge &e=edge[i];
            if(e.cap>0 && dis[e.to]<mi){
                mi=dis[e.to];
            }
        }
        gap[dis[u]=mi+1]++;
        if(u!=s)u=edge[pre[u]].to;
    }
    return ans;
}