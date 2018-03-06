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
int f=1;
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
	while (cin >> n >> m){
            if(f==1){
                    f=0;
    if(n==1&&m==1){
        cin>>x;
        for(int i=0;i<x;i++)
            cin>>a>>b;
            if(x==0)
                cout<<0;
            else
                cout<<1;
    }
    else{
        vector<vector<int>>gMap;
        gMap.resize(max(n,m)+1);
        cin>>x;
        for(int i=0;i<x;i++){
            cin>>a>>b;
            gMap[a].push_back(b);
        }
        int result=bMatch(max(n,m),gMap);
        cout<<result;
        }
	}
	else{
	     if(n==1&&m==1){
        cin>>x;
        for(int i=0;i<x;i++)
            cin>>a>>b;
            cout<<endl;
            if(x==0)
                cout<<0;
            else
                cout<<1;
    }
    else{
        vector<vector<int>>gMap;
        gMap.resize(max(n,m)+1);
        cin>>x;
        for(int i=0;i<x;i++){
            cin>>a>>b;
            gMap[a].push_back(b);
        }
        int result=bMatch(max(n,m),gMap);
        cout<<endl;
        cout<<result;
        }
	}
}    return 0;}

