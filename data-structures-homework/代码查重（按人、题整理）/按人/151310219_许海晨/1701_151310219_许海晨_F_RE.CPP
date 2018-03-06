#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

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

const int MAXN=1100;
class MST
{
private:
    int d[MAXN];
    int num_v;
    int G[MAXN][MAXN];
    long long ans;
    long long t_ans;
    int counts[MAXN];
public:
    void init()
    {
        memset(G,0,sizeof(G));
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
            G[u][v]=G[v][u]=c;
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
            for(int i=0;i<=num_v;i++)
            {
                if(G[v][i]>0)
                {
                    if(d[i]>G[v][i])
                    {
                        d[i]=G[v][i];
                        node q;
                        q.number=i;
                        q.shortcost=d[i];
                        que.push(q);
                    }
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
