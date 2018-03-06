#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<vector>
#include<cmath>
#include<cstring>
#include<unordered_map>
#include<queue>


using namespace std;


int main()
{
	int n;
	while(cin>>n)
	{
		priority_queue<int,vector<int>,greater<int>> pq;
		for(int i=0;i<n;++i)
		{
			int temp;
			cin>>temp;
			pq.push(temp);
		}
		int ans=0;
		while(pq.size()>=2)
		{
			int t1,t2;
			t1=pq.top();
			pq.pop();
			t2=pq.top();
			pq.pop();
			//cout<<t1<<' '<<t2<<endl;
			ans+=(t1+t2);
			pq.push(t1+t2);
		}
		cout<<ans<<endl;
	}
	return 0;
}



