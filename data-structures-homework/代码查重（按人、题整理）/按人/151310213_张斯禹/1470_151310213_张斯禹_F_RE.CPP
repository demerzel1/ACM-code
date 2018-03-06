#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <functional>
#include <cmath>
#include <memory.h>
#include <cstdio>
#include <sstream>
#include <set>

using namespace std;
#define MAXN 1005
#define EDGE pair<pair<int,int>,int>

vector <pair<pair<int,int>,int> > edge;
bool visited[MAXN];
vector <int> nxt[MAXN];

int cmp(const pair<pair<int,int>,int>& a,const pair<pair<int,int>,int>& b)
{
    return a.second-b.second;
}

int main()
{
    int n,m;
    int num1,num2,value;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        edge.clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&num1,&num2,&value);
            edge.push_back({{num1,num2},value});
        }
        int ans=0,trueans=0;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d",&num1);
            ans+=edge[num1-1].second;
        }
        sort(edge.begin(),edge.end(),cmp);
        memset(visited,false,sizeof(visited));
        for(int i=0;i<n;i++)
            nxt[i].clear();
        for(int i=0;i<m;i++)
        {
            bool flag=false;
            int p1=edge[i].first.first,p2=edge[i].first.second;
            queue<int> _p1;
            bool p_visited[MAXN]={false};
            _p1.push(p1);
            while(_p1.size())
            {
                for(int j=0;j<nxt[_p1.front()].size();j++)
                {
                    if(nxt[_p1.front()][j]==p2)
                    {
                        flag=true;
                        break;
                    }
                    if(!p_visited[nxt[_p1.front()][j]])
                    {
                        _p1.push(nxt[_p1.front()][j]);
                        p_visited[nxt[_p1.front()][j]]=true;
                    }
                }
                if(flag)
                    break;
                _p1.pop();
            }
            if(!flag)
            {
                nxt[p1].push_back(p2);
                nxt[p2].push_back(p1);
                trueans+=edge[i].second;
            }
        }
        if(ans==trueans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

