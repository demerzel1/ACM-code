#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <deque>
using namespace std;

vector<int> S;
deque<int> T;
int main()
{
	int n,m;
	int i;
	scanf("%d%d",&n,&m);
	if(m==1)
	{
		for(i=1;i<=n;i++)
		  printf("%d ",i);
		return 0;
	}
	S.push_back(1);

	for(i=2;i<=n;i++)
	   T.push_back(i);
	if(m!=n-1)
	  m--;
	for(i=1;i<=m;i++)
	{
		if(i%2)
		{
			int x=T.back();
			S.push_back(x);
			T.pop_back();
			if(i==m)
			{
				while(!T.empty())
				{
					x=T.back();
			        S.push_back(x);
			        T.pop_back();
				}
			}
		}
		else
		{
			int x=T.front();
			S.push_back(x);
			T.pop_front();
			if(i==m)
			{
				while(!T.empty())
				{
					x=T.front();
			        S.push_back(x);
			        T.pop_front();
				}
			}
		}
	}

	for(i=0;i<S.size();i++)
	 printf("%d ",S[i]);
	return 0;
}
