#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool visited[105];
vector<int> AdjList[105];
int N,M,x,ans[105],mxi,t;
void dfs(int u,int k){
    visited[u]=1;
    ans[k]++;
    for(int i=0;i<AdjList[u].size();i++){
        int v=AdjList[u][i];
        if(!visited[v]) dfs(v,k);
    }
}
int main(){
    while(scanf("%d",&N),N){
        mxi=1;
        for(int i=1;i<=N;i++){
            AdjList[i].clear();
            scanf("%d",&M);
            while(M--){
                scanf("%d",&x);
                AdjList[i].push_back(x);
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++)
                visited[j]=0;
        ans[i]=0;
        dfs(i,i);
        if(ans[i]>ans[mxi])
            mxi=i;
        }
        printf("%d\n",mxi);
    }
    return 0;
}
