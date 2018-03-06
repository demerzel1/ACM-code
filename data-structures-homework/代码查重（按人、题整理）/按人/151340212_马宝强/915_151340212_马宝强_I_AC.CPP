#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define Max_value 1000005
using namespace std;
int N,temp;
int main()
{
    cin.sync_with_stdio(false);
    while(cin>>N)
    {
        priority_queue<int, vector<int> ,greater<int> > q;
        int sum=0;
        for(int i=1;i<=N;i++)
        {
            cin>>temp;
            q.push(temp);
        }
        while(q.size()!=1)
        {
            int t1=q.top();q.pop();
            int t2=q.top();q.pop();
            sum+=t1+t2;
            q.push(t1+t2);
        }
        cout<<sum<<endl;
    }
    return 0;
}

