#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int parent[1010];

struct edge
{
    int u, v;
    double val;
    friend bool operator < (edge a, edge b)
    {
        return a.val < b.val;
    }
};

int Find(int x)
{
    if(parent[x] == -1) return x;
    return Find(parent[x]);
}

double Kruskal(int x, edge e[])
{
    double ans = 0;
    memset(parent, -1, sizeof(parent));
    sort(e, e+x);
    for(int i=0;i<x;i++)
    {
        int t1 = Find(e[i].u), t2 = Find(e[i].v);
        if(t1!=t2)
        {
            ans += e[i].val;
            parent[t1] = t2;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        edge e[m], test[m];
        int count = 0;
        for(int i=0;i<m;i++)
            cin >> e[i].u >> e[i].v >> e[i].val;
        for(int i=0;i<n-1;i++)
        {
            int x;
            cin >> x;
            test[count++] = e[x-1];
        }
        if(Kruskal(m, e) == Kruskal(count, test))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

