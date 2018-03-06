//2

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1005;

int matrix[MAX][MAX];
int value[MAX];
int N,M;

bool dfs(int curr,int rest_money,int& max_value)
{
    if(value[curr]>max_value){
        max_value = value[curr];
    }

    queue<pair<int,int> > q;
    for(int i=1;i<=N;i++){
        if(matrix[curr][i]!=0){
            q.push(pair<int,int>(i,matrix[curr][i]));
        }
    }

    while(!q.empty()){
        pair<int,int> next = q.front();
        q.pop();

        if(rest_money>=next.second){
            dfs(next.first,rest_money-next.second,max_value);
        }
    }
}

int main()
{
    //bool visited[MAX];
    int L;
    while(cin>>N>>M>>L){
        memset(value,0,sizeof(value));
        memset(matrix,0,sizeof(matrix));
        //memset(visited,false,sizeof(visited));
        for(int i=0;i<M;i++){
            int u,v,c;
            cin>>u>>v>>c;
            matrix[u][v] = matrix[v][u] = c;
        }
        for(int i=1;i<=N;i++){
            cin>>value[i];
        }

        int ans = value[1];
        //visited[1] = true;
        dfs(1,L,ans);
        cout<<ans<<endl;
    }
    return 0;
}

