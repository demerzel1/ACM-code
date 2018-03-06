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

const int maxn=2505;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a) {
    return a<-eps? -1:a>eps;
}

int n;
int a[maxn][maxn];

vector<pii> g[maxn];
vector<pii> mst[maxn];
int v[maxn];
pii dis[maxn];
bool flag;
int max_dis[maxn];


void prim() {
    memset(v,0,sizeof(v));
    for(int i=1; i<=n; i++) {
        dis[i].second=INF;
        dis[i].first=-1;
    }
    dis[1].second=0;
    int ans=0;
    for(int i=1; i<=n; i++) {
        int mark=-1;
        for(int j=1; j<=n; j++) {
            if(!v[j]) {
                if(mark==-1)
                    mark=j;
                else if(dis[j].second<dis[mark].second)
                    mark=j;
            }
        }
        if(mark==-1)
            break;
        v[mark]=1;
        ans+=dis[mark].second;
        if(dis[mark].first!=-1) {
            int x=dis[mark].first;
            mst[mark].push_back(make_pair(x,dis[mark].second));
            mst[x].push_back(make_pair(mark,dis[mark].second));
//            cout<<mark<<' '<<x<<' '<<dis[mark].second<<endl;
        }
        for(int j=0; j<g[mark].size(); j++) {
            if(!v[g[mark][j].first]) {
                int x=g[mark][j].first;
                if(g[mark][j].second<dis[x].second) {
//                    cout<<x<<endl;
                    dis[x].first=mark;
                    dis[x].second=g[mark][j].second;
                }
            }
        }
    }
    return;
}



void dfs(int x,int fa,int root) {
    for(int i=0; i<mst[x].size(); i++) {
        int v=mst[x][i].first;
        if(v==fa)
            continue;
        max_dis[v]=max(max_dis[x],mst[x][i].second);
        if(a[root][v]!=max_dis[v]) {
            flag=true;
            return;
        }
        dfs(v,x,root);
        if(flag)
            return;
    }
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin>>a[i][j];
            g[i].push_back(make_pair(j,a[i][j]));
            g[j].push_back(make_pair(i,a[i][j]));
        }
    }
    for(int i=1; i<=n; i++) {
        if(a[i][i]!=0) {
            flag=true;
            break;
        }
    }
    if(flag) {
        cout<<"NOT MAGIC"<<endl;
        return 0;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(a[i][j]!=a[j][i]) {
                flag=true;
                break;
            }
        }
        if(flag)
            break;
    }
    if(flag) {
        cout<<"NOT MAGIC"<<endl;
        return 0;
    }
    prim();
//    for(int i=1;i<=n;i++){
//        for(int j=0;j<mst[i].size();j++){
//            cout<<i<<' '<<mst[i][j].first<<' '<<mst[i][j].second<<endl;
//        }
//    }
    for(int i=1; i<=n; i++) {
        max_dis[i]=0;
        dfs(i,0,i);
        if(flag) {
            cout<<"NOT MAGIC"<<endl;
            return 0;
        }
    }
    cout<<"MAGIC"<<endl;
    return 0;
}
