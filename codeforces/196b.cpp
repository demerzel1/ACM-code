#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define prt(k) cout<<#k"="<<k<<" "
const int inf = 1e9;
const int N = 1555;
int vis[N][N][2];
int n, m;
char a[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1,  0, 0};
bool dfs ( int x, int y ) {
    int xx = ( x % n + n ) % n, yy = ( y % m + m ) % m;
    if ( a[xx][yy] == '#' ) return 0;
    if ( vis[xx][yy][0] != -inf )
        return vis[xx][yy][0] != x || vis[xx][yy][1] != y;
    vis[xx][yy][0] = x, vis[xx][yy][1] = y;
    for ( int i = 0; i < 4; i++ )
        if ( dfs ( x + dx[i], y + dy[i] ) )
            return 1;
    return 0;
}
int main() {
    cin >> n >> m;
    for ( int i = 0; i < n; i++ ) cin >> a[i];
    int sx = 0, sy = 0;
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < m; j++ ) {
            vis[i][j][0] = -inf;
            if ( a[i][j] == 'S' )
                sx = i, sy = j;
        }
    if ( dfs ( sx, sy ) )
        puts ( "Yes" );
    else puts ( "No" );
    return 0;
}
