#include <bits/stdc++.h>
using namespace std;
#define INF 0xffff
struct edge {int to,cost;edge(int x, int y){to = x; cost = y;}};
typedef pair<int, int> P1;
vector<edge> G[1005];
int d[1005];
int V, E, C;
void dijkstra(int s)
{
    priority_queue<P1, vector<P1>, greater<P1> > que;
    fill(d, d + V + 3, INF);
    d[s] = 0;
    que.push(P1(0,s));
    while(!que.empty())
    {
        P1 p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); ++i)
        {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(P1(d[e.to], e.to));
            }
        }
    }
}

void reset()
{
    for(int i = 0; i < V + 1; ++i)
    {
        G[i].clear();
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin >> V)
    {
        cin >> E >> C;
        vector<P1> pir;
        for(int i = 0; i < E; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            G[a].push_back(edge(b, c));
        }
        dijkstra(1);
        for(int i = 0; i < V; ++i)
        {
            int t;
            cin >> t;
            pir.push_back(P1(t,i+1));
        }
        sort(pir.begin(), pir.end());
        for(int i = pir.size() - 1; i >= 0; --i)
        {
            if(d[pir[i].second] <= C)
            {
                cout << pir[i].first << endl;
                break;
            }
        }
        reset();
    }
    return 0;
}

