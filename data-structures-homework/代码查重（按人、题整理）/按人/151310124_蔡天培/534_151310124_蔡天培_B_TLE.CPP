#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<vector>
#include<cmath>
#include<cstring>
#include<unordered_map>

using namespace std;

int Evalue[1005];
bool visited[1005];
unordered_map<int,unordered_map<int,int>> route;
int n,m;
long long l;

long long dfs(int scene,long long ev,long long cost)
{
	long long result=ev;
	int currsel;
	for(auto i=route[scene].begin();i!=route[scene].end();++i)
	{
		if(cost+i->second <= l)
		{
			visited[i->first]=true;
//			cerr<<i->first<<' '<<ev+Evalue[i->first]<<' '<<cost+i->second<<endl;
			long long maxr=max(result,dfs(i->first,ev+Evalue[i->first],cost+i->second));
			visited[i->first]=false;
			if(maxr>result)
			{
				result=maxr;
				currsel=i->first;
			}
		}
	}
	return result;
}

int main()
{
	while(cin>>n>>m>>l)
	{
		route.clear();
		fill(begin(Evalue),end(Evalue),0);
		fill(begin(visited),end(visited),false);
		for(int i=0;i<m;i++)
		{
			int u,v,c;
			cin>>u>>v>>c;
			route[u][v]=c;
			route[v][u]=c;
		}
		for(int i=1;i<=n;++i)
		{
			cin>>Evalue[i];
		}
		long long r=dfs(1,0,0);
		if(r==0)
			r=Evalue[1];
		cout<<r<<endl;
	}
	return 0;
}

