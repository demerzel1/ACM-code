#include <bits/stdc++.h>
using namespace std;
struct edge {int u, v, cost;
bool operator < (const edge &a) const
{
    if(cost < a.cost) return true;
    return false;
}
edge(int x, int y,int z){u = x; v = y;cost = z;}
};
vector<edge> edges;
vector<edge> te;
int V, E;
class US
{
private:
    vector<int> par;
    vector<int> rank1;
    int n;
public:
    void init(int x)
    {
        n = x;
        par.resize(n + 3);
        rank1.resize(n + 3);
        for(int i = 0; i < n; ++i)
        {
            par[i] = i;
            rank1[i] = 0;
        }
    }

    int find(int x)
    {
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y)
    {
        x = find(x); y = find(y);
        if(x == y) return;
        if(rank1[x] < rank1[y])
        {
            par[x] = y;
        }
        else
        {
            par[y] = x;
            if(rank1[x] < rank1[y]) rank1[x]++;
        }
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    void reset()
    {
        par.clear(); rank1.clear();
    }
};

int main()
{
    while(cin >> V >> E)
    {
        US t;
        for(int i = 0; i < E; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edges.push_back(edge(a,b,c));
        }
        te = edges;
        sort(edges.begin(),edges.end());
        t.init(V);
        int res = 0,res2 = 0;
        for(int i = 0; i < E; ++i)
        {
            edge e = edges[i];
            if(!t.same(e.u, e.v))
            {
                t.unite(e.u,e.v);
                res += e.cost;
            }
        }

        for(int i = 0; i < V - 1; ++i)
        {
            int g;
            cin >> g;
            //cout << edges[g-1].cost << " ";
            res2 += te[g-1].cost;
        }
        //cout << res << " " << res2 << endl;
        if(res2 == res) cout << "YES" << endl;
        else cout << "NO" << endl;
        t.reset();
        edges.clear();
    }
    return 0;
}



