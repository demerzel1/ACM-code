#include<bits/stdc++.h>
using namespace std;

int a[35][35],b[35][35];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d",&a[i][j]);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    m--;
    while(m--) {
        memset(b,0,sizeof(b));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                for(int k=1; k<=n; k++) {
                    b[i][j]+=a[i][k]*a[k][j];
                }
            }
        }
        memcpy(a,b,sizeof(b));
//        for(int i=1; i<=n; i++) {
//            for(int j=1; j<=n; j++) {
//                printf("%d ",a[i][j]);
//            }
//            printf("\n");
//        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
