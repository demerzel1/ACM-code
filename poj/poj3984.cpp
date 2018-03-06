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
#define maxn 105
typedef pair<int,int> pii;

int mp[6][6];
pii ans[maxn];
pii tans[maxn];
bool vis[6][6];
int cnt;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

void dfs(int x,int y,int d){
    if(x==4&&y==4){
        if(d<cnt){
            for(int i=0;i<d;i++){
                ans[i]=tans[i];
            }
            cnt=d;
        }
        return;
    }
    for(int k=0;k<4;k++){
        int tx=x+dx[k];
        int ty=y+dy[k];
        if(tx>=0&&tx<5&&ty>=0&&ty<5){
            if(mp[tx][ty]==0&&!vis[tx][ty]){
                tans[d].first=tx;
                tans[d].second=ty;
                vis[tx][ty]=true;
                dfs(tx,ty,d+1);
                vis[tx][ty]=false;
            }
        }
    }
    return;
}

int main(){
    while(cin>>mp[0][0]){
        cnt=INT_MAX;
        memset(tans,0,sizeof(tans));
        memset(ans,0,sizeof(ans));
        for(int i=1;i<5;i++)
            cin>>mp[0][i];
        for(int i=1;i<5;i++)
            for(int j=0;j<5;j++)
            cin>>mp[i][j];
        tans[0].first=0;
        tans[0].second=0;
        dfs(0,0,1);
        for(int i=0;i<cnt;i++){
            cout<<"("<<ans[i].first<<", "<<ans[i].second<<")\n";
        }
    }
    return 0;
}
