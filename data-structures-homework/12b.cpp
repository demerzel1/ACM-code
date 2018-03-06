#include<bits/stdc++.h>
using namespace std;
#define N 105

int main(){
    int m,n,i,j;
    while(scanf("%d%d",&n,&m)&&(n||m)){
        int g[N][N]={0};
        int edge[N]={0};
        for(i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            g[a][b]=1;
            edge[b]++;
        }
        for(i=0;i<n;i++){
            int pos=1;
            while(pos<=n&&edge[pos]!=0)
                pos++;
            edge[pos]=-1;
            if(pos==n+1) break;
            printf("%d ",pos);
            for(j=1;j<=n;j++){
                if(g[pos][j])
                    edge[j]--;
            }
        }
        printf("\n");
    }
    return 0;
}
