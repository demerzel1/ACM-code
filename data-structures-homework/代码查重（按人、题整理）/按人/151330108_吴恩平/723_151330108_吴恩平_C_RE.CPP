#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define maxn 10005
using namespace std;

bool vis[maxn][maxn];

int main()
{
    int n, m, q, x, y;
    vector<string> strs;
    while(~scanf("%d%d", &n, &m)){
        scanf("%d", &q);
        strs.clear();
        memset(vis, false, sizeof(vis));
        for(int i=1; i<=q; i++){
            scanf("%d%d", &x, &y);
            if(x<=n && x>=1 && y<=m && y>=1){
                if(!vis[x][y]){
                    strs.push_back("YES");
                    vis[x][y]=true;
                }else{
                    strs.push_back("NO");
                }
            }else strs.push_back("NO");

        }
        for(int i=0; i<q; i++)
            cout << strs[i] << endl;
    }
    return 0;
}

