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

const int maxn=1005;
const int INF=100000000;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a) {
    return a<-eps? -1:a>eps;
}

int dx[]= {0,0,-1,1};
int dy[]= {1,-1,0,0};

int n,m;
char mp[maxn][maxn];
int path[4][maxn][maxn];

void bfs(int C) {
    queue<pii> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mp[i][j]=='0'+C) {
                path[C][i][j]=0;
                q.push(make_pair(i,j));
            } else {
                path[C][i][j]=INF;
            }
        }
    }
    while(!q.empty()) {
        pii x=q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int tx=x.first+dx[i];
            int ty=x.second+dy[i];
            if(tx>=0&&tx<n&&ty>=0&&ty<m&&mp[tx][ty]!='#'&&path[C][tx][ty]==INF) {
                path[C][tx][ty]=path[C][x.first][x.second]+1;
                q.push(make_pair(tx,ty));
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>mp[i];
    for(int i=1; i<=3; i++)
        bfs(i);
    int ans=INF;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int t=1;
            for(int k=1;k<=3;k++)
                t+=max(0,path[k][i][j]-1);
          //  cout<<t<<endl;
            ans=min(ans,t);
        }
    }
//    cout<<ans<<endl;
    for(int k=1; k<=3; k++) {
        int t1=INF,t2=INF;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mp[i][j]=='0'+k) {
                    if(k==1) {
                        t1=min(t1,path[2][i][j]);
                        t2=min(t2,path[3][i][j]);
                    } else if(k==2) {
                        t1=min(t1,path[1][i][j]);
                        t2=min(t2,path[3][i][j]);
                    } else if(k==3) {
                        t1=min(t1,path[1][i][j]);
                        t2=min(t2,path[2][i][j]);
                    }
                }
            }
        }
        ans=min(ans,t1+t2-2);
    }
    if(ans>=INF/10) {
        ans=-1;
    }
    cout<<ans<<endl;
    return 0;
}
