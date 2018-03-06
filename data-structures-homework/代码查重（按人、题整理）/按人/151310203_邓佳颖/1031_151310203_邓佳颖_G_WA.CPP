//Code here
#include <iostream>
#include <vector>
#include <cstring>
const int MAXN=200;
using namespace std;
vector<int> adj[MAXN];
int visit[MAXN];
void dfs(int n){
    if(visit[n]==1) return;
    visit[n]=1;
    for(int i=0;i<adj[n].size();i++){
        dfs(adj[n][i]);
    }
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int q;
        memset(adj,0,sizeof(adj));
        memset(visit,0,sizeof(visit));
        scanf("%d",&q);
        vector<int> in;
        for(int i=0;i<q;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            in.push_back(a-1);
            adj[a-1].push_back(b-1);
        }
        int ans=0;
        for(int i=0;i<q;i++){
            if(visit[in[i]]==0){
                dfs( in[i] );
                ans++;
            }
        }
        cout << ans<< endl;
    }

    return 0;
}

