#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int> > G;
int match[1000];
bool used[1000];
bool dfs(int u)
{
    for(int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        if(!used[v])
        {
            used[v] = true;
            if((match[v] == -1) || (dfs(match[v])))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxmatching()
{
    int res = 0;
    memset(match, -1, sizeof(match));
    for(int v = 0; v < n + 1; ++v)
    {
        memset(used, 0, sizeof(used));
        if(dfs(v)) res++;
    }
    return res;
    
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin >> n >> m)
    {
        G.resize(n + 3);
        int t;
        cin >> t;
        for(int i = 0; i < t; ++i)
        {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);
        }
        cout << maxmatching() << endl;
        G.clear();
    }
}

