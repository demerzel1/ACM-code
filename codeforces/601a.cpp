#include<bits/stdc++.h>
using namespace std;
#define maxv 405
#define INF 1000000
int cost[maxv][maxv];
int d[maxv];
bool used[maxv];
int V;
void dijt ( int s ) {
//   cout<<111<<endl;
    fill ( d, d + V + 1, INF );
    fill ( used, used + V + 1, false );
    d[s] = 0;
    while ( true ) {
        int v = -1;
        for ( int u = 1; u <= V; u++ ) {
            if ( !used[u] && ( v == -1 || d[u] < d[v] ) ) v = u;
        }
        if ( v == -1 ) break;
        used[v] = true;
        for ( int u = 1; u <= V; u++ ) {
            d[u] = min ( d[u], d[v] + cost[v][u] );
        }
    }
}

void dijr ( int s ) {
    //  cout<<222<<endl;
    fill ( d, d + V + 1, INF );
    fill ( used, used + V + 1, false );
    d[s] = 0;
    while ( true ) {
        int v = -1;
        for ( int u = 1; u <= V; u++ ) {
            if ( !used[u] && ( v == -1 || d[u] < d[v] ) ) v = u;
        }
        if ( v == -1 ) break;
        used[v] = true;
        for ( int u = 1; u <= V; u++ ) {
            if ( cost[v][u] == 1 )
                cost[v][u] = INF;
            else if ( cost[v][u] != 1 )
                cost[v][u] = 1;
            //       printf("du=%d dv=%d\n",d[u],d[v]);
            d[u] = min ( d[u], d[v] + cost[v][u] );
            //   printf("v=%d u=%d cost=%d\n",v,u,cost[v][u]);
            //   printf("du=%d dv=%d\n",d[u],d[v]);
            if ( cost[v][u] == 1 )
                cost[v][u] = INF;
            else if ( cost[v][u] != 1 )
                cost[v][u] = 1;
        }
    }
}
int main() {
    int m;
    memset ( cost, INF, sizeof ( cost ) );
    scanf ( "%d%d", &V, &m );
    for ( int i = 0; i < m; i++ ) {
        int a, b;
        scanf ( "%d%d", &a, &b );
        cost[a][b] = 1;
        cost[b][a] = 1;
    }
    if ( m == V * ( V - 1 ) / 2 ) {
        printf ( "-1\n" );
        return 0;
    }
    if ( cost[1][V] != 1 ) {
        dijt ( 1 );
    }
    if ( cost[1][V] == 1 ) {
        dijr ( 1 );
    }
    if ( d[V] == INF ) {
        printf ( "-1\n" );
        return 0;
    } else {
        printf ( "%d\n", d[V] );
    }
    return 0;
}
