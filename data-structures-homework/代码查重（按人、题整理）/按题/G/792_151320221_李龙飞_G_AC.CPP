#include <iostream>
#include <cstring>
using namespace std;

bool g[110][110];
bool flag, visit[110];
int match[110];
int p, n;

bool dfs(int u)
{
    for(int i=1;i<=n;i++)
    {
        if(g[u][i] && !visit[i])
        {
            visit[i] = true;
            if(match[i] == -1 || dfs(match[i]))
            {
                match[i] = u;
                return true;
            }
        }
    }
    return false;
}
int hungarian()
{
    int ans = 0, i;
    for(i=1;i<=p;i++)
    {
        memset(visit, false, sizeof(visit));
        if(dfs(i))
            ans++;
    }
    return ans;
}

int main()
{
    while(cin >> p >> n)
    {
        memset(g, false, sizeof(g));
        memset(match, -1, sizeof(match));
        int k, i, x, y;
        cin >> k;
        for(i=0;i<k;i++)
        {
            cin >> x >> y;
            g[x][y] = true;
        }
        cout << hungarian() << endl;
    }
    return 0;
}

