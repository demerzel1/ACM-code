#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <map>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

struct node
{
    int x;
    long long value;
    node(int x1,long long v1)
    {
        x=x1;
        value=v1;
    }
};

queue<node>  q1;
priority_queue<long long,vector<long long>,less<long long> > q2;
long long v[1005];
int vis[1005];
double cost[1005][1005];
int ans;





int main()
{
    long long money,m,z;
    int x,y,n,i;
    while(cin>>n>>m>>money)
    {
        memset(cost,0,sizeof(cost));
        memset(vis,-1,sizeof(vis));
        vector<int>  tt[1000];
        for(i=1;i<=m;i++)
        {
            cin>>x>>y>>z;
            tt[x].push_back(y);
            tt[y].push_back(x);
            cost[x][y]=z*1.0;
            cost[y][x]=z*1.0;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>v[i];
        }
        if(m==0)   cout<<v[1]<<endl;
        else
        {
        while(!q1.empty())   q1.pop();
        node Node(1,money);
        q1.push(Node);
        q2.push(v[1]);
        vis[1]=1;
        while(!q1.empty())
        {
            node pp=q1.front();
            int x1=pp.x;
            q1.pop();
            if(tt[x1].size()!=0)
            {
                int SIZE=tt[x1].size();
                for(i=0;i<SIZE;i++)
                {
                    if(vis[tt[x1][i]]==-1&&pp.value-cost[tt[x1][i]][x1]>=0)
                    {
                        q2.push(v[tt[x1][i]]);
                        node NO(tt[x1][i],pp.value-cost[tt[x1][i]][x1]);
                        q1.push(NO);
                    }
                }
            }
        }
        cout<<q2.top()<<endl;
        }
    }
    return 0;
}

