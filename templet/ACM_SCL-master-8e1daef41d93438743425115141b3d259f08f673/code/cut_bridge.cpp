int head[MAXN],tot;
struct Edge{
	int to,next;
}edge[MAXM<<1];
void clear(){
	tot=0;
	memset(head,0,sizeof(head));
}
void addedge(int u,int v){
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}//单向边

vector<int>cut;
vector<pair<int,int> >bridge;
int dfn[MAXN],low[MAXN],cnt;
void tarjan(int u,int pre){
	int part=(pre==-1?0:1);
	dfn[u]=low[u]=++cnt;
	for(int i=head[u]; ~i; i=edge[i].next){
		int v=edge[i].to;
		pair<int,int> f=make_pair(min(u,v),max(u,v));
		if(dfn[v]==-1){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<=low[v]){
				if(++part==2){
					cut.push_back(u);
				}//割点
				if(dfn[u]<low[v]){
					bridge.push_back(f);
				}//桥
			}
		}
		else if(v!=pre&& dfn[v]<dfn[u]){
			low[u]=min(low[u],dfn[v]);
		}
	}
}
void solve(){
	cut.clear();
	bridge.clear();
	cnt=0;
	memset(dfn,-1,sizeof(dfn));
	memset(low,0,sizeof(low));
	for(int i=0;i<n;i++){
		if(dfn[i]==-1){
			tarjan(i,-1);
		}
	}
}
