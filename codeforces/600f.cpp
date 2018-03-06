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

const int maxn=2100;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a) {
    return a<-eps? -1:a>eps;
}
const int A=1000;

int a,b,m;
int ans;

struct edge {
    int u;
    int v;
    int col;
    edge(int a=0,int b=0,int c=0):u(a),v(b),col(c) {}
};

vector<edge> e;
set<int> usable_col[maxn];
vector<int> v[maxn];
int use_col[maxn][maxn];


int find_col(int u,int ei,int pre_col) {
    int v;
    if(e[ei].u==u)
        v=e[ei].v;
    else
        v=e[ei].u;
    for(int col:usable_col[u]){
        if(col!=pre_col&&usable_col[v].count(col))
            return col;
    }
    for(int col:usable_col[u]){
        if(col!=pre_col)
            return col;
    }
    return -1;
}

void delate_col(int u,int col) {
    if(col==-1)
        return;
    if(use_col[u][col]==0)
        return;
    use_col[u][col]=0;
    usable_col[u].insert(col);
}

void add_col(int u,int col,int ei){
    if(use_col[u][col]!=0)
        return;
    use_col[u][col]=ei;
    auto it=usable_col[u].find(col);
    if(it!=usable_col[u].end())
        usable_col[u].erase(it);
}

void color_edge(int u,int ei,int col){
    int pre_col=e[ei].col;
    if(pre_col==col)
        return;
    e[ei].col=col;
    delate_col(u,pre_col);
    add_col(u,col,ei);
    int v;
    if(e[ei].u==u)
        v=e[ei].v;
    else
        v=e[ei].u;
    delate_col(v,pre_col);
    if(use_col[v][col]!=0){
        int x=use_col[v][col];
        int tcol=pre_col;
        if(pre_col==-1){
            tcol=find_col(v,x,col);
        }
        color_edge(v,x,tcol);
    }
    add_col(v,col,ei);
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    //cin>>a>>b>>m;
    scanf("%d%d%d",&a,&b,&m);
    int x,y;
    for(int i=0;i<=b+A;i++){
        usable_col[i].clear();
    }
    e.push_back(edge(-1,-1,-1));
    for(int i=1; i<=m; i++) {
        //cin>>x>>y;
        scanf("%d%d",&x,&y);
        y+=A;
        e.push_back(edge(x,y,-1));
        v[x].push_back(i);
        v[y].push_back(i);
    }
    for(int j=1; j<=a; j++) {
        ans=std::max((int)v[j].size(),ans);
    }
    for(int j=1; j<=b; j++) {
        ans=std::max((int)v[j+A].size(),ans);
    }
    for(int i=1; i<=ans; i++) {
        for(int j=1; j<=a; j++) {
            usable_col[j].insert(i);
        }
        for(int j=1; j<=b; j++) {
            usable_col[j+A].insert(i);
        }
    }
  //  cout<<111<<endl;
    for(int i=1; i<=a; i++) {
        for(int j=0;j<v[i].size();j++){
            int t=v[i][j];
            if(e[t].col==-1){
                color_edge(i,t,find_col(i,t,-1));
            }
        }
    }
    for(int i=A+1; i<=A+b; i++) {
        for(int j=0;j<v[i].size();j++){
            int t=v[i][j];
            if(e[t].col==-1){
                color_edge(i,t,find_col(i,t,-1));
            }
        }
    }
  //  cout<<ans<<endl;
    printf("%d\n",ans);
    for(int i=1; i<=m; i++) {
  //      cout<<e[i].col<<' ';
        printf("%d ",e[i].col);
    }
    return 0;
}
