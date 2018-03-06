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
#include <iomanip>
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
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=500005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}


vector<int> g[maxn];
int in[maxn];
int dp[maxn];
bool vis[maxn];
int ind=0;

void dfs(int x,int d){
    vis[x]=true;
    if(in[x]==1){
        dp[ind]=d;
        ind++;
        return;
    }
    for(int i=0;i<g[x].size();i++){
        if(!vis[g[x][i]]){
            dfs(g[x][i],d+1);
        }
    }
    return;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int x,y;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        in[x]++;
        in[y]++;
    }
    vis[1]=true;
    int ans=0;
    for(int i=0;i<g[1].size();i++){
        int x=g[1][i];
        ind=0;
        dfs(x,1);
        sort(dp,dp+ind);
        for(int j=1;j<ind;j++){
            dp[j]=max(dp[j-1]+1,dp[j]);
        }
        ans=max(ans,dp[ind-1]);
//        printf("ans=%d\n",ans);
    }
    cout<<ans<<"\n";
    return 0;
}
