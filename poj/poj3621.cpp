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

bool flag=false;
int cnt[maxn];
vector<edge> G[maxn];
int dis[maxn];
int vis[maxn];

struct edge{
    int from;
    int to;
    int weight;
};

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


int main(){

}
