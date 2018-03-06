#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<vector>
#include<cmath>
#include<cstring>
#include<unordered_map>


using namespace std;

bool dfs(int now, vector<vector<int>> & adjL, vector<bool> & visited, vector<int> & match)
{
	for(int next=0;next<adjL[now].size();++next)
	{
		if(visited[adjL[now][next]]==false)
		{
			visited[adjL[now][next]]=true;
			if(match[adjL[now][next]]==-1 || dfs(match[adjL[now][next]],adjL,visited,match))
			{
				match[adjL[now][next]]=now;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int n,m,q;
	while(cin>>n>>m>>q)
	{
		vector<vector<int>> adjL(n+m);
		for(int i=0;i<q;++i)
		{
			int a,b;
			cin>>a>>b;
			a--,b--;
			adjL[a].push_back(b+n);
			adjL[b+n].push_back(a);
		}
		vector<bool> visited(n+m,false);
		vector<int> match(n+m,-1);
		int ans=0;
		for(int i=0+n;i<m+n;++i)
		{
			if(match[i]==-1)
			{
				fill(begin(visited),end(visited),false);
				if(dfs(i,adjL,visited,match))
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}



