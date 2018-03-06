#include<bits/stdc++.h>
using namespace std;
#define maxn 3005
int n;
vector<int> g[maxn];
int d[maxn];
vector<int> h;
int ans[maxn];

void bfs() {
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(d[i]==1)
            q.push(i);
    }
    while(!q.empty()) {
        int u=q.front();
        d[u]=0;
        q.pop();
        int sz=g[u].size();
        for(int i=0; i<sz; i++) {
            int v=g[u][i];
            if(d[v]>0) {
                d[v]--;
                if(d[v]==1) {
                    q.push(v);
                }
            }
        }
    }
    return;
}

void dfs(int x) {
    int sz=g[x].size();
    //  cout<<"sz "<<sz<<"x="<<x<<"\n";
    for(int i=0; i<sz; i++) {
        int v=g[x][i];
        if(ans[v]==-1) {
            //       cout<<i<<" ";
            ans[v]=ans[x]+1;
            dfs(v);
        }
    }
}

int main() {
    memset(ans,-1,sizeof(ans));
    scanf("%d",&n);
    int a,b;
    for(int i=0; i<n; i++) {
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        d[a]++;
        d[b]++;
    }
    bfs();
    for(int i=1; i<=n; i++) {
        if(d[i]>0) {
            ans[i]=0;
            // cout<<i<<" ";
        }
    }
    for(int i=1; i<=n; i++) {
        if(ans[i]==0) {
            dfs(i);
        }
    }
    for(int i=1; i<=n; i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}
