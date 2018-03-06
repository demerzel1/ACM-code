#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<vector>
#include<cmath>
#include<cstring>
#include<unordered_map>


using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	int n,m,q;
	unordered_map<int,unordered_map<int,int>> route;
	while(cin>>n>>m>>q)
	{
		route.clear();
		for(int i=0;i<q;++i)
		{
			int x,y;
			cin>>x>>y;
			if(route[x][y]==1)
				cout<<"NO"<<endl;
			else
			{
				route[x][y]=1;
				cout<<"YES"<<endl;
			}
		}
	}
	return 0;
}



