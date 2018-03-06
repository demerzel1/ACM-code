#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n, m, q, x, y;
    vector<string> strs;
    vector<bool> v;
    vector< vector<bool> > vis;
    while(~scanf("%d%d", &n, &m)){
        scanf("%d", &q);
        strs.clear(), v.clear(), vis.clear();
        for(int i=0; i<=m; i++) v.push_back(false);
        for(int i=0; i<=n; i++) vis.push_back(v);
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

