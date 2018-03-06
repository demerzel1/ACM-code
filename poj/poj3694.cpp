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
#include<climits>
using namespace std;
#define maxn 100020
#define maxm 220000

int n,m;
int q;
int lcnt;
vector<int> g[maxn];
int dfn[maxn];
int low[maxn];
int status[maxn];
int par[maxn];
bool cutedge[maxn];
int ecnt;
int Dfn[maxn];
int ind;

void init() {
    memset(dfn,0,sizeof(dfn));
    memset(Dfn,0,sizeof(Dfn));
    memset(low,0,sizeof(low));
    memset(status,0,sizeof(status));
    memset(cutedge,false,sizeof(cutedge));
    ind=lcnt=ecnt=0;
    for(int i=0; i<=n+10; i++) {
        g[i].clear();
        par[i]=i;
    }
}

void tarjan(int c,int from,int d) {
    dfn[c]=low[c]=++ind;
    Dfn[c]=d;
    status[c]=1;
    int sz=g[c].size();
    int v;
    for(int i=0; i<sz; i++) {
        v=g[c][i];
        if(!status[v]) {
            status[v]=1;
            par[v]=c;
            tarjan(v,c,d+1);
            low[c]=min(low[c],low[v]);
            if(low[v]>dfn[c]) {
                cutedge[v]=true;
                ecnt++;
                //   printf("cutedge v=%d\n",v);
            }
        } else if(v!=from) {
            low[c]=min(low[c],dfn[v]);
        }
    }
    //status[c]=1;
    return;
}

void lca(int u,int v) {
//    if(Dfn[u]<Dfn[v])
//        swap(u,v);
    while(Dfn[u]>Dfn[v]) {
  //      printf("u=%d v=%d dfnu=%d dfnv=%d\n",u,v,dfn[u],dfn[v]);
        if(cutedge[u]) {
            ecnt--;
            cutedge[u]=false;
        }
        u=par[u];
     //   printf("now u=%d\n",u);
    }
    while(Dfn[v]>Dfn[u]){
        if(cutedge[v])
            ecnt--;
        cutedge[v]=false;
        v=par[v];
    }
    while(u!=v) {
     //   printf("new now u=%d v=%d dfnu=%d dfnv=%d\n",u,v,dfn[u],dfn[v]);
        if(cutedge[u])
            ecnt--;
        if(cutedge[v])
            ecnt--;
        cutedge[u]=false;
        cutedge[v]=false;
        u=par[u];
        v=par[v];
    //    printf("new now u=%d v=%d\n",u,v);
        //printf("in\n");
    }
}

int main() {
    int cas=0;
    while(scanf("%d%d",&n,&m)!=EOF) {
        if(n==0&&m==0)
            break;
        init();
        int a,b;
        for(int i=0; i<m; i++) {
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        tarjan(1,-1,1);
        scanf("%d",&q);
        printf("Case %d:\n",++cas);
        for(int i=0; i<q; i++) {
            scanf("%d%d",&a,&b);
            // printf("a=%d b=%d\n",a,b);
            lca(a,b);
            printf("%d\n",ecnt);
        }
        printf("\n");
    }
    return 0;
}

/*
6 5
1 2
2 3
3 4
2 5
5 6
1
4 6
*/




/*
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
#include<climits>
using namespace std;
#define maxn 100000
#define maxm 220000
typedef struct node {
    int to;
    int cnt;
    node(int t,int c) {
        to=t;
        cnt=c;
    }
} node;
int n,m;
int q;
int lcnt;
vector<node> g[maxn];
int dfn[maxn];
int low[maxn];
int status[maxn];
int par[maxn];
bool cutedge[maxn];
int ecnt;
int Dfn[maxn];
int ind;

void init() {
    memset(dfn,0,sizeof(dfn));
    memset(Dfn,0,sizeof(Dfn));
    memset(low,0,sizeof(low));
    memset(status,0,sizeof(status));
    memset(cutedge,false,sizeof(cutedge));
    ind=lcnt=ecnt=0;
    for(int i=0; i<=n+10; i++) {
        g[i].clear();
        par[i]=i;
    }
}

void tarjan(int c,int from,int d) {
    dfn[c]=low[c]=++ind;
    Dfn[c]=d+1;
    status[c]=1;
    int sz=g[c].size();
    int v;
    for(int i=0; i<sz; i++) {
        v=g[c][i].to;
        if(!status[v]) {
            status[v]=1;
            par[v]=c;
            tarjan(v,g[c][i].cnt,d+1);
            low[c]=min(low[c],low[v]);
            if(low[v]>dfn[c]) {
                cutedge[v]=true;
                ecnt++;
                //   printf("cutedge v=%d\n",v);
            }
        } else if(status[i]==1&&g[c][i].cnt!=from) {
            low[c]=min(low[c],dfn[v]);
        }
    }
    status[c]=2;
    return;
}

void lca(int u,int v) {
    if(Dfn[u]<Dfn[v])
        swap(u,v);
    while(Dfn[u]>Dfn[v]) {
  //      printf("u=%d v=%d dfnu=%d dfnv=%d\n",u,v,dfn[u],dfn[v]);
        if(cutedge[u]) {
            ecnt--;
            cutedge[u]=false;
        }
        u=par[u];
     //   printf("now u=%d\n",u);
    }
    while(u!=v) {
     //   printf("new now u=%d v=%d dfnu=%d dfnv=%d\n",u,v,dfn[u],dfn[v]);
        if(cutedge[u])
            ecnt--;
        if(cutedge[v])
            ecnt--;
        cutedge[u]=false;
        cutedge[v]=false;
        u=par[u];
        v=par[v];
    //    printf("new now u=%d v=%d\n",u,v);
        //printf("in\n");
    }
}

int main() {
    int cas=0;
    while(scanf("%d%d",&n,&m)!=EOF) {
        if(n==0&&m==0)
            break;
        init();
        int a,b;
        for(int i=0; i<m; i++) {
            scanf("%d%d",&a,&b);
            g[a].push_back(node(b,lcnt));
            g[b].push_back(node(a,lcnt));
            lcnt++;
        }
        tarjan(1,-1,1);
        scanf("%d",&q);
        printf("Case %d:\n",++cas);
        for(int i=0; i<q; i++) {
            scanf("%d%d",&a,&b);
            // printf("a=%d b=%d\n",a,b);
            lca(a,b);
            printf("%d\n",ecnt);
        }
        printf("\n");
    }
    return 0;
}

/*
6 5
1 2
2 3
3 4
2 5
5 6
1
4 6
*/
