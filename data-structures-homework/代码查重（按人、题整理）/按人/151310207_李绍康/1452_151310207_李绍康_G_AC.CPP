#include <iostream>
#include <string.h>

using namespace std;
int n,m,k,link[201],match[201][201];
bool used[201];
int Dfs(int a)
{
    int i;
    for(i = 0;i < m;i++)
    {
        if(used[i] == 0 && match[a][i] == 1)
        {
            used[i] = 1;
            if(link[i] == -1 || Dfs(link[i]))
            {
                link[i] = a;
                return 1;
            }
        }
    }
    return 0;
}
int BipartiteMatching()
{
    int i,res = 0;
    for(i = 0;i < n;i++)
    {
        memset(used,0,sizeof(used));
        if(Dfs(i))
            res++;
    }
    return res;
}

int main()
{
    int a,b,i;
    while(cin >> n >> m)
    {
        cin >> k;
        memset(match,0,sizeof(match));
        memset(link,-1,sizeof(link));
        for(i = 0;i < k;i++)
        {
            cin >> a >> b;
            match[a - 1][b - 1] = 1;
        }
        cout << BipartiteMatching() << endl;
    }
    return 0;
}

