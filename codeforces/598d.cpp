#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <climits>
#include <ctime>
#include <complex>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

char mp[1005][1005];
int vis[1005][1005];
map<int,int> ans;
int ind=1;
int tans=0;
int n,m,k;
void dfs(int x,int y){
    vis[x][y]=ind;
    for(int i=0;i<4;i++){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx>=0&&tx<n&&ty>=0&&ty<m&&mp[tx][ty]=='*'){
            tans++;
        }
    }
    for(int i=0;i<4;i++){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx>=0&&tx<n&&ty>=0&&ty<m&&vis[tx][ty]==0&&mp[tx][ty]=='.'){
            dfs(tx,ty);
        }
    }
    return;
}

int main(){

    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>mp[i];
    }
    while(k--){
        tans=0;
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(vis[x][y]!=0){
            cout<<ans[vis[x][y]]<<"\n";
        }else{
            dfs(x,y);
            ans[ind]=tans;
            cout<<tans<<"\n";
            ind++;
        }
    }
    return 0;
}
