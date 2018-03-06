#include<bits/stdc++.h>
using namespace std;

int dist[320][320];
int main(){
    int n,r,t=0,cst;
    while(1){
        scanf("%d%d",&n,&r);
        if(!n&&!r)
            break;
        map<string,int> indx;
        string u,v;
        memset(dist,-1,sizeof(dist));
        int cnt=0;
        for(int i=0;i<r;i++){
            cin>>u>>v>>cst;
            if(!indx[u])
                indx[u]=++cnt;
            if(!indx[v])
                indx[v]=++cnt;
            dist[indx[u]][indx[v]]=dist[indx[v]][indx[u]]=cst;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dist[i][j]=dist[j][i]=max(dist[i][j],min(dist[i][k],dist[k][j]));
        string src,dst;
        cin>>src>>dst;
        printf("Scenario #%d\n",++t);
        printf("%d tons\n\n",dist[indx[src]][indx[dst]]);
    }
    return 0;
}
