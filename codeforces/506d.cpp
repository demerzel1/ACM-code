#include <bits/stdc++.h>
using namespace std;

const int MAX=100005;
unordered_map <int,int> mp[MAX];
int sz[MAX];
vector <int> G[MAX];
int get_map(int C,int x) {
	if(!mp[C].count(x)) return x;
	return mp[C][x]=get_map(C,mp[C][x]);
}
void Union(int C,int x,int y) {
	x=get_map(C,x);
	y=get_map(C,y);
	if(x>y) swap(x,y);
	if(x!=y) {
		mp[C][y]=x;
	}
}
int main() {
	int n,m;
	cin>>n>>m;
	int x,y;
	int temp=m;
	while(m--) {
		int C;
		scanf("%d %d %d",&x,&y,&C);
		G[x].push_back(C);
		G[y].push_back(C);
		Union(C,x,y);
	}
	for(int C=1; C<=n; C++) {
		sort(G[C].begin(),G[C].end());
		G[C].erase(unique(G[C].begin(),G[C].end()),G[C].end());
		sz[C]=G[C].size();
	}
	cin>>m;
	map <pair <int,int> ,int> ans_map;
	while(m--) {
		scanf("%d %d",&x,&y);
		if(x>y) swap(x,y);
		pair <int,int> t=make_pair(x,y);
		if(sz[x]>sz[y]) swap(x,y);
		if(ans_map.count(t)) {
			printf("%d\n",ans_map[t]);
			continue;
		}
		int ans=0;
		for(int i=0; i<G[x].size(); i++) {
			int C=G[x][i];
			if(get_map(C,x)==get_map(C,y)) ans++;
		}
		ans_map[t]=ans;
		printf("%d\n",ans);
	}
	//while(true);
	return 0;
}
