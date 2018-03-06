#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define maxn 1000005
using namespace std;

class node{
    public:
        int x, y;
    public:
        friend bool operator < (node n1, node n2)
        {
            if(n1.x==n2.x) return n1.y < n2.y;
            return n1.x < n2.x;
        }
};

int main()
{
    int n, m, q, x, y;
    node nn;
    vector<string> strs;
    map<node, int> vis;
    while(~scanf("%d%d", &n, &m)){
        scanf("%d", &q);
        strs.clear(), vis.clear();
        for(int i=1; i<=q; i++){
            scanf("%d%d", &x, &y);
            nn.x=x, nn.y=y;
            if(x<=n && x>=1 && y<=m && y>=1){
                if(vis.find(nn)==vis.end()){
                    strs.push_back("YES");
                    vis[nn]=1;
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

