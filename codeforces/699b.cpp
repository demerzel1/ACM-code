#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
bool mp[1005][1005];
int cntx[maxn];
int cnty[maxn];
int sum = 0;
int main() {
    int n, m;
    scanf ( "%d%d", &n, &m );
    char c;
  //  printf ( "%d %d\n", n, m );
    getchar();
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= m; j++ ) {
            scanf ( "%c", &c );
       //     printf ( "1%c", c );
            if ( c == '*' ) {
                mp[i][j] = true;
                cntx[i]++;
                cnty[j]++;
                sum++;
               // printf ( "%d %d %d %d %d\n", i, j, cntx[i], cnty[j], sum );
            }
        }
        getchar();
    }
    bool flag = true;
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= m; j++ ) {
            if ( mp[i][j] ) {
                int cnt = cntx[i] + cnty[j] - 1;
                if ( cnt == sum ) {
                    flag = false;
                    printf ( "YES\n" );
                    printf ( "%d %d\n", i, j );
                    return 0;
                }
            } else {
                int cnt = cntx[i] + cnty[j];
                if ( cnt == sum ) {
                    flag = false;
                    printf ( "YES\n" );
                    printf ( "%d %d\n", i, j );
                    return 0;
                }
            }
        }
    }
    if ( flag ) {
        printf ( "NO" );
    }
    return 0;
}
