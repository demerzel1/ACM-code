#include<bits/stdc++.h>
using namespace std;
#define N 100010
vector<int>g[N];
vector<int> head;
int n,m,h,t,hh,tt;
bool vis[N];

bool judge(int u,int v) {
    int lu = g[u].size();
    int lv = g[v].size();
    memset(vis,0,sizeof(vis));
    int hnum = 0,tnum = 0;
    for(int j=0;  j<lu;j++)
        if(!vis[g[u][j]] && g[u][j]!=v) {
            vis[g[u][j]] = true;
            hnum++;
        }
    for(int j=0; j<lv;j++)
        if(g[v][j]!=u) {
            if(!vis[g[v][j]]) tnum++;
            else if(hnum>hh) {
                vis[g[v][j]] = false;
                hnum--,tnum++;
            }
        }
    if(hnum>=hh && tnum>=tt) {
        h = hh, t = tt;
        printf("YES\n");
        printf("%d %d\n",u,v);
//        cout<<"YES\n";
//        cout<<u<<" "<<v<<"\n";
        for(int j=0;j<lu&&h;j++)
            if(g[u][j]!=v && vis[g[u][j]]) {
                h--;
//                cout<<g[u][j]<<" ";
                printf("%d ",g[u][j]);
            }
            printf("\n");
           // puts("");
//        cout<<"\n";
        for(int j=0; j<lv && t;j++)
            if(g[v][j]!=u&&!vis[g[v][j]]) {
                t--;
                printf("%d ",g[v][j]);
             //   cout<<g[v][j]<<" ";
            }
      // puts("");
      printf("\n");
  //      cout<<"\n";
        return true;
    }
    return false;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cin>>n>>m>>hh>>tt;
    scanf("%d%d%d%d",&n,&m,&hh,&tt);
    for(int i=0; i<m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
//        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=n;i++)
        if(g[i].size()>hh)
            head.push_back(i);
    int sz=head.size();
    for(int i=0; i<sz;i++) {
        h = head[i];
        int szh=g[h].size();
        for(int j=szh-1; j>=0;j--) {
            t = g[h][j];
            if(g[t].size()>tt)
                if(judge(h,t))
                    return 0;
        }
    }
    printf("NO\n");
  //  cout<<"NO\n";
    return 0;
}
