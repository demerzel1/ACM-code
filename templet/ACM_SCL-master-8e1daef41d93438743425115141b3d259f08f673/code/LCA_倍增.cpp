//链式前向星
const int MAXN = 10010;//节点个数
const int DEP = 20;//递归深度，log(MAXN)
int fa[MAXN][DEP];//fa[i][j]表示结点i的第2^j个祖先 
int dep[MAXN];//深度数组
//int dis[MAXN]//两点间距离

void dfs(int u,int f){
    fa[u][0]=f;
    for(int i=1;i<DEP;i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v!=f){
        	dep[v]=dep[u]+1;
        	//dis[v]=dis[u]+edge[i].val;
        	dfs(v,u);
        }
    }
}
void bfs(int root) {
	queue<int>que; 
	dep[root] = 0; 
	fa[root][0]=root; 
	que.push(root); 
	while(!que.empty()) {
		int now=que.front(); que.pop();
		for(int i=1;i<DEP;i++){
			fa[now][i]=fa[fa[now][i-1]][i-1];
		}
		for(int i=head[now];~i;i=edge[i].next){
			int v=edge[i].to;
			if(v==fa[now][0])	continue; 
			dep[v]=dep[now]+1; 
			//dis[v]=dis[now]+edge[i].val;
			fa[v][0]=now;
			que.push(v);
		}
	}
}//防爆栈..

int LCA(int a,int b) {
	if(dep[a]>dep[b])swap(a,b);
	int t=dep[b]-dep[a];
	for(int i=0;i<DEP;i++) if(t&(1<<i)) b=fa[b][i];
	if(a==b)	return a;
	
	for(int i=DEP-1;i>=0;i--)
		if(fa[a][i]!=fa[b][i])
			a=fa[a][i]; b=fa[b][i];
	return fa[a][0]; 
}

int dis(int x,int y){
	int t=LCA(x,y);
	return dep[x]+dep[y]-2*dep[t];//边权为1
	//return dis[x]+dis[y]-2*dis[t];
}