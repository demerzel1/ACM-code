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

const int maxn=100005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int n;
map<int,int> cnt[maxn];
int maxx[maxn];
ll sum[maxn];
ll ans[maxn];
vector<int> g[maxn];

void uni(int u,int v){
    if(cnt[u].size()<cnt[v].size()){
        swap(cnt[u],cnt[v]);
        swap(maxx[u],maxx[v]);
        swap(sum[u],sum[v]);
    }
    for(auto it=cnt[v].begin();it!=cnt[v].end();it++){
        cnt[u][it->first]+=it->second;
        if(maxx[u]==cnt[u][it->first]){
            sum[u]+=it->first;
        }else if(maxx[u]<cnt[u][it->first]){
            maxx[u]=cnt[u][it->first];
            sum[u]=it->first;
        }
    }
}

void dfs(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==fa)
            continue;
        dfs(g[u][i],u);
        uni(u,g[u][i]);
    }
    ans[u]=sum[u];
}

int main(){
    scanf("%d",&n);
    int x;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        cnt[i][x]++;
        maxx[i]=1;
        sum[i]=x;
    }
    int a,b;
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}
