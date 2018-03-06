#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <vector>
#define Max_Value 1000000
using namespace std;
long long  n,m;
int temp;
long long Max;
int main()
{
    cin.sync_with_stdio(false);
    while(cin>>n>>m)
    {
        Max=m;
        priority_queue<int> q;
        for(int i=1;i<=n;i++)
        {
            cin>>temp;
            q.push(temp);
        }
        while(!q.empty())
        {
            m=q.top();q.pop();
            if(m>0)
            {
                Max*=m;
                continue;
            }
            if(m==0)
            	break;
            if((!q.empty()&&q.top()<0)||Max<0)
            {
                Max*=m;
            }
        }
        cout<<Max<<endl;
    }
}

