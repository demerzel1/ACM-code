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
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=200005;
const int maxm=200005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}


int N,M;
int fa[maxn];

struct edge{
    int x,y,id;
    ll w;
    edge(int x=0,int y=0,ll w=0,int id=0):x(x),y(y),w(w),id(id){}
}e[maxm];

struct node{
    int y;
    ll w;
    node(int y=0,ll w=0):y(y),w(w){}
};

vector<node> mst[maxn];
int dep[maxn];
bool vis[maxn];
int father[maxn][30];
ll heav[maxn][30];


bool cmp(edge a,edge b){
    return a.w<b.w;
}

int getfather(int x){
    if(x==fa[x])
        return x;
    else
        return fa[x]=getfather(fa[x]);
}
ll kruscal(){
    ll ans=0;
    sort(e+1,e+M+1,cmp);
    int cnt=N;
    for(int i=1;i<=N;i++)
        fa[i]=i;
    for(int i=1;i<=M;i++){
        int t1=getfather(e[i].x);
        int t2=getfather(e[i].y);
        if(t1!=t2){
            fa[t1]=t2;
            ans+=e[i].w;
            mst[e[i].x].push_back(node(e[i].y,e[i].w));
            mst[e[i].y].push_back(node(e[i].x,e[i].w));
            if(cnt==1)
                break;
        }
    }
    return ans;
}

void dfs(int x,int d){
    dep[x]=d;
    vis[x]=true;
    for(auto it=mst[x].begin();it!=mst[x].end();it++){
        if(!vis[it->y]){
            dfs(it->y,d+1);
            father[it->y][0]=x;
            heav[it->y][0]=it->w;
       //     cout<<x<<' '<<it->w<<"\n";
        }

    }
}

void lcainit(){
    for(int j=1;j<25;j++){
        for(int i=1;i<=N;i++){
            if(~father[i][j-1]){
                father[i][j]=father[father[i][j-1]][j-1];
                heav[i][j]=max(heav[i][j-1],heav[father[i][j-1]][j-1]);
            }
        }
    }
}

ll lca(int u,int v,int w){
   ll res1=0,res2=0;
    if(dep[u]<dep[v])
        swap(u,v);
    for(int b=25;b>=0;b--){
      //  cout<<father[u][b]<<endl;
        if(father[u][b]==-1)
            continue;
        if(dep[father[u][b]]>=dep[v]){
            res1=max(res1,heav[u][b]);
            u=father[u][b];
        }
    }
    //cout<<u<<' '<<v<<" uv\n";
    if(u==v)
        return w-res1;
    for(int b=25;b>=0;b--){
        if(father[u][b]!=father[v][b]){
            res1=max(res1,heav[u][b]);
            u=father[u][b];
            res2=max(res2,heav[v][b]);
            v=father[v][b];
        }
    }
   // cout<<res1<<' '<<res2<<endl;
    return w-max(max(heav[u][0],heav[v][0]),max(res1,res2));
}

ll ans[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //    freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    cin>>N>>M;
    ll tt=0;
    for(int i=1;i<=M;i++){
        cin>>e[i].x>>e[i].y>>e[i].w;
        e[i].id=i;
    }
    tt=kruscal();
   // cout<<tt<<endl;
    memset(father,0xff,sizeof(father));
    memset(heav,0,sizeof(heav));
    memset(vis,false,sizeof(vis));
    dfs(1,1);
    lcainit();
    for(int i=1;i<=M;i++){
        ans[e[i].id]=tt+lca(e[i].x,e[i].y,e[i].w);
    }
    for(int i=1;i<=M;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
