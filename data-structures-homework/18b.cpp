#pragma warning (disable:4996)
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <ctime>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 40001;

struct Edge {
    int e,v;
    int n;
} edge[2*N];

int n,m,e_num,head[N];
int x[N],y[N],z[N],f[N],dist[N],vis[N];


int find(int x) {
    if(f[x]!=x)
        return f[x]=find(f[x]);
    return f[x];
}
void AddEdge(int a,int b,int c) {
    edge[e_num].e=b;
    edge[e_num].v=c;
    edge[e_num].n=head[a];
    head[a]=e_num++;
    edge[e_num].e=a;
    edge[e_num].v=c;
    edge[e_num].n=head[b];
    head[b]=e_num++;
}

void tarjan(int k) {
    int i;
    vis[k]=1;
    f[k]=k;
    for(i=1; i<=m; i++) {
        if(x[i]==k && vis[y[i]]) z[i]=find(y[i]);
        if(y[i]==k && vis[x[i]]) z[i]=find(x[i]);
    }
    for(i=head[k]; i!=-1; i=edge[i].n) {
        if(!vis[edge[i].e]) {
            dist[edge[i].e]=dist[k]+edge[i].v;
            tarjan(edge[i].e);
            f[edge[i].e]=k;
        }
    }
}

int main() {
    int t,a,b,c,i;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        e_num=0;
        memset(head,-1,sizeof(head));
        for(i=1; i<n; i++) {
            scanf("%d%d%d",&a,&b,&c);
            AddEdge(a,b,c);
        }

        for(i=1; i<=n; i++) {
            x[i]=y[i]=z[i]=0;
        }
        for(i=1; i<=m; i++) {
            scanf("%d%d",&a,&b);
            x[i]=a;
            y[i]=b;
        }

        memset(vis,0,sizeof(vis));
        dist[1]=0;
        tarjan(1);

        for(i=1; i<=m; i++)
            printf("%d\n",dist[x[i]]+dist[y[i]]-2*dist[z[i]]);
    }
    return 0;
}
