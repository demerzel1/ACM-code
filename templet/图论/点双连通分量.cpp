/*
	��˫��ͨ���� POJ 2942
	���˫��ͨ������Tarjan�㷨:
	������һ��,dfn[x]��ʾ������x��ʱ�����low[x]��ʾ��xΪ������������������ϵ
	����ʱ�����С�ĵ㡣�����������аѱ߷Ž�ջ����ͨ��v�жϳ�u�Ǹ����(��
	low[v]>=dfn[u],u��v�ĸ���)����ô�Ͳ��ϰѱ߳�ջ��ֱ��(u,v)��ջΪֹ����ʱ����
	�����бߵ����νڵ㼯�Ͼ����µ�һ����˫��ͨ������ 
*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 1001
#define M 2000001
using namespace std;
int n,m,ans,top,u[M],v[M];
int tt,dfn[N],low[N],color[N];
int sz,to[M],pre[M],last[N];
bool map[N][N],mark[N],in[N];
void Ins(int a,int b){
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void init(){
	int i,j,a,b;sz=0;
	memset(map,0,sizeof(map));
	memset(last,0,sizeof(last));
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		map[a][b]=1;map[b][a]=1;
	}
	for(i=1;i<=n;i++) for(j=1;j<=n;j++){
		if(!map[i][j] && i!=j)
			Ins(i,j);
	}
}
bool dfs(int x){
	for(int i=last[x];i;i=pre[i]){
		if(!in[to[i]]) continue;
		if(color[to[i]]==-1){
			color[to[i]]=color[x]^1;
			if(!dfs(to[i])) return 0;
		} else 
		if(color[to[i]]==color[x]) return 0;
	}
	return 1;
}
void check(int x,int y){
	memset(in,0,sizeof(in));
	while(u[top]!=x || v[top]!=y){
		in[u[top]]=1;in[v[top]]=1;
		top--;
	}
	in[x]=1;in[y]=1;top--;
	memset(color,-1,sizeof(color));
	color[x]=0;
	if(!dfs(x)){
		for(int i=1;i<=n;i++){
			if(in[i])
				mark[i]=1;
		}
	}
}
void Tarjan(int x,int from){
	dfn[x]=++tt;low[x]=tt;
	for(int i=last[x];i;i=pre[i]){
		if(to[i]==from) continue;
		if(!dfn[to[i]]){
			u[++top]=x;v[top]=to[i];
			Tarjan(to[i],x);
			low[x]=min(low[x],low[to[i]]);
			if(low[to[i]]>=dfn[x]) check(x,to[i]);
		} 
		else low[x]=min(low[x],dfn[to[i]]);
	}
}
void solve(){
	top=tt=ans=0;
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(mark,0,sizeof(mark));
	for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i,0);
	for(int i=1;i<=n;i++) if(mark[i]) ans++;
	printf("%d\n",n-ans);
}
int main(){
	while(scanf("%d%d",&n,&m)){
		if(n==0 && m==0) break;
		init();
		solve();
	}
	return 0;
}

