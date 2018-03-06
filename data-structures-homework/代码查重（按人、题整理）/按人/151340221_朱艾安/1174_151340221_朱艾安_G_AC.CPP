#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

bool DFS(vector<vector<int>> gMap,bool used[110],int match[110],int v){
    for(int i=0;i<gMap[v].size();i++){
        int u=gMap[v][i];
        if(!used[u]){
            used[u]=true;
            if(match[u]==-1 || DFS(gMap,used,match,match[u])){
                match[u]=v;
                return true;
            }
        }
    }
    return false;
}

int bMatch(int leftCnt,vector<vector<int>> gMap){
    int res=0;
    bool used[110]={false};
    int match[110]={0};
    memset(match,-1,sizeof(match));
    for(int i=1;i<=leftCnt;i++){
        memset(used,0,sizeof(used));
        if(DFS(gMap,used,match,i)){res++;}
    }
    return res;
}

int main()
{
    int cnt1,cnt2;
    while(scanf("%d %d",&cnt1,&cnt2)!=EOF){
        int rule;
        scanf("%d",&rule);

        vector<vector<int>> gMap;
        gMap.resize(cnt1+1);
        for(int i=1;i<=rule;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            gMap[a].push_back(b);
        }

        int result=bMatch(cnt1,gMap);
        printf("%d\n",result);
        }
    return 0;
}

