#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<map>
using namespace std;

map<int,vector<int> > mp;
map<int,int>::iterator it;
map<int,int> visit;
int bfs(int src,int h){
    int cnt=1;
    visit.clear();
    visit[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        int sz=mp[u].size();
        for(int i=0;i<sz;i++){
            int v=mp[u][i];
            if(!visit.count(v)){
                visit[v]=1+visit[u];
                if(visit[v]<=h)
                    cnt++;
                q.push(v);
            }
        }
    }
    return cnt;
}

int main(){
    int n;
    int g=1;
    while(cin>>n){
        if(n==0) break;
        mp.clear();
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        int k,j;
        while(cin>>k>>j){
            if(k==0&&j==0)
                break;
            int fa=mp.size()-bfs(k,j);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",g,fa,k,j);
            g++;
        }
    }
    return 0;
}
