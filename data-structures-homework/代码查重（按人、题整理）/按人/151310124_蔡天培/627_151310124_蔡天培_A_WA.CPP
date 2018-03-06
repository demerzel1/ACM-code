#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<vector>
#include<cmath>
#include<cstring>


using namespace std;

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		vector<int> a(n);
		int minusNumber;
		int minusMax=0x80000000;
		bool zeroAppeared=false;
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
			if(a[i]<0)
			{
				minusNumber++;
				if(a[i]>minusMax)
				{
					minusMax=a[i];
				}
			}
			else if(a[i]==0)
				zeroAppeared=true;
		}
		if(m<0)
			minusNumber++;
		for(int i=0;i<n;++i)
		{
			if(a[i]==0)
				continue;
			if(a[i]>0)
				m*=a[i];
			else
			{
				if(minusNumber&1 && a[i]==minusMax)
				{
					minusMax=0;
				}
				else
					m*=a[i];
			}
		}
		if(m<0 && zeroAppeared)
			m=0;
		cout<<m<<endl;
	}
	return 0;
}
