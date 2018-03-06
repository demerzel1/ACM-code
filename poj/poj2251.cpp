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
#define maxn 35

char mp[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
int step[maxn][maxn][maxn];

int L,R,C;

int dx[]= {1,-1,0,0,0,0};
int dy[]= {0,0,1,-1,0,0};
int dz[]= {0,0,0,0,1,-1};

struct point {
    int x,y,z;
    point(int xx=0,int yy=0,int zz=0) {
        x=xx;
        y=yy;
        z=zz;
    }
};

point S,E;

int bfs() {
    queue<point> q;
    q.push(S);
    vis[S.x][S.y][S.z]=true;
    while(!q.empty()) {
        point tp=q.front();
        q.pop();
        for(int i=0; i<6; i++) {
            int tx=tp.x+dx[i];
            int ty=tp.y+dy[i];
            int tz=tp.z+dz[i];
            if(tx<0||tx>=L||ty<0||ty>=R||tz<0||tz>=C)
                continue;
            if(!vis[tx][ty][tz]&&mp[tx][ty][tz]!='#') {
                step[tx][ty][tz]=step[tp.x][tp.y][tp.z]+1;
                vis[tx][ty][tz]=true;
                q.push(point(tx,ty,tz));
                if(E.x==tx&&E.y==ty&&E.z==tz) {
                    return step[tx][ty][tz];
                }
            }
        }
    }
    return -1;
}

int main() {
    while((cin>>L>>R>>C)&&(L&&R&&C)) {
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        memset(step,0,sizeof(step));
        for(int i=0; i<L; i++) {
            for(int j=0; j<R; j++) {
                scanf("%s",mp[i][j]);
                for(int k=0; k<C; k++) {
                    if(mp[i][j][k]=='S') {
                        S.x=i;
                        S.y=j;
                        S.z=k;
                    }
                    if(mp[i][j][k]=='E') {
                        E.x=i;
                        E.y=j;
                        E.z=k;
                    }
                }
            }
        }
        int ans=bfs();
        if(ans==-1) {
            cout<<"Trapped!\n";
        } else {
            printf("Escaped in %d minute(s).\n",ans);
        }
    }
    return 0;
}
