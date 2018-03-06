#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#define MAXN 10010

using namespace std;

bool DFS(vector<vector<int>>gMap,bool used[MAXN],int match[MAXN],int v){
    for(int i=0;i<gMap[v].size();i++){
        int u=gMap[v][i];
        if(!used[u]){
            used[u]=true;
            if(match[u]==-1||DFS(gMap,used,match,match[u])){
                match[u]=v;
                return true;
            }
        }
    }
    return false;
}

int bMatch(int leftCnt,vector<vector<int>>gMap){
    int res=0;
    bool used[MAXN]={false};
    int match[MAXN]={0};
    memset(match,-1,sizeof(match));
    for(int i=0;i<leftCnt;i++){
        memset(used,0,sizeof(used));
        if(DFS(gMap,used,match,i)){res++;}
    }
    return res;
}

int main()
{
    int a,b,n,x,m;
	while (scanf("%d %d",&n,&m)!=EOF){
    if(n==1&&m==1){
        scanf("%d",&x);
        for(int i=0;i<x;i++)
            scanf("%d,%d",&a,&b);
            if(x==0)
                printf("0\n");
                //cout<<0<<endl;
            else
            printf("1\n");
                //cout<<1<<endl;
    }
    else{
        vector<vector<int>>gMap;
        gMap.resize(max(n,m)+1);
        scanf("%d",&x);
        for(int i=0;i<x;i++){
            scanf("%d %d",&a,&b);
            //cin>>a>>b;
            gMap[a].push_back(b);
        }
        int result=bMatch(max(n,m),gMap);
        printf("%d\n",result);
        }
	}
    return 0;
}

