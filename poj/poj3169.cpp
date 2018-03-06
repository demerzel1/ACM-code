#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <algorithm>
#include<climits>
using namespace std;
#define maxn 1005
int n,ml,md;
struct edge {
    int next;
    int w;
};
bool flag=false;
int cnt[maxn];
vector<edge> G[maxn];
int dis[maxn];
int vis[maxn];
void spfa(int s) {
    for(int i=1; i<=n; i++) {
        dis[i]=INT_MAX;
        vis[i]=0;
    }
    dis[s]=0;
    vis[s]=1;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty()) {
        //   cout<<111<<endl;
        int u=Q.front();
        Q.pop();
        vis[u]=0;
        //   cout<<G[u].size()<<endl;
        for(int i=0; i<G[u].size(); i++) {
            int v=G[u][i].next;
            int wei=G[u][i].w;
            //      printf("u=%d v=%d wei=%d\n",u,v,wei);
            if(dis[v]>dis[u]+wei) {
                dis[v]=dis[u]+wei;
                if(!vis[v]) {
                    cnt[v]++;
                    if(cnt[v]>n) {
                        flag=true;
                        break;
                    }
                    vis[v]=1;
                    Q.push(v);
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d",&n,&ml,&md);
    for(int i=1; i<=ml; i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edge e;
        e.next=b;
        e.w=c;
        G[a].push_back(e);
    }
    for(int i=1; i<=md; i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edge e;
        e.next=a;
        e.w=-c;
        G[b].push_back(e);
    }
    spfa(1);
    if(flag) {
        printf("-1\n");
    } else if(dis[n]==INT_MAX) {
        printf("-2\n");
    } else {
        printf("%d\n",dis[n]);
    }
    return 0;
}
