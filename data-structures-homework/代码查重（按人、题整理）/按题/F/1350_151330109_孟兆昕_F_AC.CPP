#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int V,m,k;

#define INF 100000
#define maxm 5000005
#define maxv 1005
int edge[maxm][3];
int mincost[maxv];
bool used[maxv];
int cost[maxv][maxv];

int prim() {
    for(int i=0; i<=V; i++) {
        mincost[i]=1000000;
    }
    mincost[1]=0;
    int res=0;
    while(true) {
        int v=-1;
        for(int u=1; u<=V; u++) {
            if(!used[u]&&(v==-1||mincost[u]<mincost[v])) {
                //      printf("u=%d v=%d mu=%d mv=%d\n",u,v,mincost[u],mincost[v]);
                v=u;
                //   cout<<"v="<<v<<endl;
            }
        }
        if(v==-1)
            break;
        used[v]=true;
        // printf("v=%d minv=%d\n",v,mincost[v]);
        res+=mincost[v];
        for(int u=1; u<=V; u++) {
            if(cost[v][u]!=0)
                mincost[u]=min(mincost[u],cost[v][u]);
            //    printf("v=%d u=%d minu=%d\n",v,u,mincost[u]);
        }
    }
    return res;
}

int main() {
    while(scanf("%d",&V)!=EOF) {
        memset(edge,0,sizeof(edge));
        memset(mincost,INF,sizeof(mincost));
        memset(used,false,sizeof(used));
        memset(cost,0,sizeof(cost));
        scanf("%d",&m);
        for(int i=1; i<=m; i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            edge[i][0]=a;
            edge[i][1]=b;
            edge[i][2]=c;
            cost[a][b]=c;
            cost[b][a]=c;
        }


        int ans=prim();
        int b[maxv];
        memset(b,0,sizeof(b));
        int cnt=0;
        map<int,int> mp;
        for(int i=0; i<V-1; i++) {
            scanf("%d",&b[i]);
            cnt+=edge[b[i]][2];
            mp[edge[b[i]][0]]++;
            mp[edge[b[i]][1]]++;
        }
        map<int,int>::iterator it1,it2;
        it1=mp.begin();
        it2=mp.end();

        if(mp.size()==V) {
            if(ans==cnt)
                printf("YES\n");
            else
                printf("NO\n");
        }

        //  cout<<ans<<" "<<cnt<<endl;

        else {
            printf("NO\n");
        }
    }
    return 0;
}


