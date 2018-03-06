const int MAXN = 1010;
const int MAXQ = 500010;//查询数的最大值

//并查集部分
//join 修改 if(t1 != t2) F[t1] = t2;
bool vis[MAXN];//访问标记 
int fa[MAXN];//祖先

//邻接表edge、query(query需要加一个查询编号id)

void add_query(int u,int v,int id)
//query u-v间的LCA，查询编号id

void total_init() {
	memset(vis,false,sizeof(vis)); 
	memset(fa,0,sizeof(fa));
}//！还要初始化并查集和两个邻接表
void LCA(int u) {
	fa[u] = u; vis[u] = true;
	for(int i = head[u]; ~i ;i=edge[i].next) {
		int v = edge[i].to; 
		if(vis[v])	continue; 
		LCA(v); join(u,v); 
		fa[Find(u)] = u;
	}
	for(int i = h[u]; ~i ;i=query[i].next) {
		int v = query[i].to; 
		if(vis[v]) answer[query[i].id]=fa[Find(v)];
	} 
}