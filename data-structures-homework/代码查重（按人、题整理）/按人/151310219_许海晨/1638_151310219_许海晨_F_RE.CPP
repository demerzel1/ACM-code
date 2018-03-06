#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct edge
{
    int to,from,cost;
};
struct node
{
    int shortcost,number;
};
bool operator <(node a,node b)
{
    return a.shortcost>b.shortcost;
}

const int MAXN=1005;
class MST
{
private:
    int d[MAXN];
    int num_v;
    vector <edge> G[MAXN];
    long long ans;
    long long t_ans;
    int counts[MAXN];
public:
    void init()
    {
        for(int i=0;i<MAXN;i++)
            G[i].clear();
        ans=0;
        t_ans=0;
    }
    void read(int n,int m)
    {
        num_v=n;
        int v,u,c;
        counts[0]=0;
        edge e;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&v,&u,&c);
            if(v==u)
                break;
            e.from=v;e.to=u;e.cost=c;
            G[v].push_back(e);
            e.from=u,e.to=v;e.cost=c;
            G[u].push_back(e);
            counts[i+1]=c;
        }
    }
    void compute()
    {
        fill(d,d+num_v+10,9999999);
        d[1]=0;
        priority_queue<node>que;
        node p;
        p.number=1;p.shortcost=0;
        que.push(p);
        while(!que.empty())
        {
            p=que.top();
            que.pop();
            int v=p.number;
            if(d[v]<p.shortcost) continue;
            ans+=p.shortcost;
            for(int i=0;i<G[v].size();i++)
            {
                edge e=G[v][i];
                if(d[e.to]>e.cost)
                {
                    d[e.to]=e.cost;
                    node q;
                    q.number=e.to;
                    q.shortcost=d[e.to];
                    que.push(q);
                }
            }
        }
        int index;
        for(int i=0;i<num_v-1;i++)
        {
            scanf("%d",&index);
            t_ans+=counts[index];
        }
        if(ans==t_ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
};
int main()
{
    int n,m;
    MST ms;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ms.init();
        ms.read(n,m);
        ms.compute();
    }
    return 0;
}

