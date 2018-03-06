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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int n,m;
char mp[maxn][maxn];
bool vis[maxn][maxn];
int ind[maxn][maxn];
map<int,int> num;
int tind=0;
int ans[maxn][maxn];
map<int,int> test;


void dfs(int x,int y){
    vis[x][y]=true;
    ind[x][y]=tind;
    num[tind]++;
    for(int k=0;k<4;k++){
        int tx=x+dx[k];
        int ty=y+dy[k];
        if(tx>=0&&tx<n&&ty>=0&&ty<m&&mp[tx][ty]=='.'&&!vis[tx][ty]){
            dfs(tx,ty);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>mp[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='.'&&!vis[i][j]){
                dfs(i,j);
                tind++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='.'){
                ans[i][j]=-1;
            }else{
                ans[i][j]=1;
                test.clear();
                for(int k=0;k<4;k++){
                    int tx=i+dx[k];
                    int ty=j+dy[k];
                    if(tx>=0&&tx<n&&ty>=0&&ty<m&&mp[tx][ty]=='.'){
                        if(test[ind[tx][ty]]==0){
                            test[ind[tx][ty]]=1;
                            ans[i][j]+=num[ind[tx][ty]];
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ans[i][j]!=-1)
                cout<<ans[i][j]%10;
            else
                cout<<".";
        }
        cout<<endl;
    }
    return 0;
}
