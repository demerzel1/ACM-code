#include <bits/stdc++.h>

using namespace std;
struct edge
{
    int next;
    int val;
    edge(int n,int v){next=n;val=v;}
};
struct place
{
    int p;
    long long e;
    place(int a,long long b){p=a;e=b;}
    friend bool operator < (const place& a,const place& b)
    {
        return a.e<b.e;
    }
};
int n,m;
map<int,vector<edge> >graph;
vector<place>Place;
long long dist[1005];
const long long inf = 10000000000;
vector<bool>visit;
void initial()
{
    graph.clear();
    Place.clear();
}
int spfa(int s)
{
    for(int i=0;i<=n;i++)
        dist[i]=inf;
    visit.resize(n+1);
    fill(visit.begin(),visit.end(),false);
    queue<int>q;
    q.push(s);
    visit[s] = true;
    dist[s] = 0;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        visit[now] = false;
        for(int i=0; i<graph[now].size(); i++)
        {
            int v = graph[now][i].next;
            int w = graph[now][i].val;

            if(dist[v]>dist[now]+w)
            {
                dist[v] = dist[now]+w;
                if(!visit[v])
                {
                    visit[v] = true;
                    q.push(v);
                }
            }

        }
    }
}

long long l;
int main()
{
   int u,v,c;
   long long e;
   while(cin>>n>>m>>l)
   {
       initial();
       for(int i=0;i<m;i++)
       {
           cin>>u>>v>>c;
           graph[u].push_back(edge(v,c));
           graph[v].push_back(edge(u,c));
       }
       for(int i=1;i<=n;i++)
       {
           cin>>e;
           Place.push_back(place(i,e));
       }
       int s = Place[0].p;
       long long value = Place[0].e;
       spfa(s);
       sort(Place.begin(),Place.end());
       for(int i=Place.size()-1;i>=0;i--)
       {
           if(dist[Place[i].p]<=l)
           {
                value = Place[i].e;
                break;
           }

       }
       cout<<value<<endl;
   }
}


