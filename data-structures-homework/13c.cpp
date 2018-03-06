#include<bits/stdc++.h>
using namespace std;

const int INF=2000000000;
int d[110][110];
int main(){
    int C,S,Q;
    int Case=0;
    while(scanf("%d%d%d",&C,&S,&Q)&&C){
        if(Case)
            printf("\n");
        for(int i=1;i<=C;i++)
            for(int j=1;j<=C;j++)
                d[i][j]=INF;
        for(int i=0;i<S;i++){
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            d[x][y]=d[y][x]=w;
        }
        for(int k=1;k<=C;k++)
            for(int i=1;i<=C;i++)
                for(int j=1;j<=C;j++)
                    d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
        printf("Case #%d\n",++Case);
        for(int i=0;i<Q;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(d[x][y]!=INF)
                printf("%d\n",d[x][y]);
            else
                printf("no path\n");
        }
    }
    return 0;
}
