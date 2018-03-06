#include<bits/stdc++.h>
using namespace std;
#define maxn 2005

int m,n;
char s[maxn][maxn];
int dx[]= {0,0,-1,-1,-1,1,1,1};
int dy[]= {1,-1,0,-1,1,1,-1,0};
void dfs(int x,int y) {
    int cnt=0;
    if(x<0||y<0||x>=n-1||y>=m-1)
        return;
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++) {
            if(s[x+i][y+j]=='*') {
                cnt++;
            }
        }
    if(cnt==1) {
        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++) {
                s[x+i][y+j]='.';
            }
        for(int i=0; i<8; i++) {
            dfs(x+dx[i],y+dy[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int i,j;
    for(i=0; i<n; i++) {
        cin>>s[i];
    }
    for(i=0; i<n-1; i++)
        for(j=0; j<m-1; j++)
            dfs(i,j);
    for(i=0; i<n; i++)
        cout<<s[i]<<"\n";
    return 0;
}
