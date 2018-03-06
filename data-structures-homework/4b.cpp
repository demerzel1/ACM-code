#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int n,a[101][101];
int DFS(int k) {
    int st[101],b[101],i,t,l,m;
    memset(b,0,sizeof(b));
    b[k]=1;
    if(k==1) l=2;
    else l=1;
    t=0;
    m=2;
    b[l]=1;
    do {
        for(i=1; i<=n; i++) {
            if((a[l][i])&&(b[i]==0)) {
                t++;
                st[t]=i;
                m++;
                b[i]=1;
            }
        }
        l=st[t];
        t--;
    } while(t>=0);
    return (m==n);
}
int main() {
    int i,j,ans;
    char c;
    scanf("%d",&n);
    while(n!=0) {
        memset(a,0,sizeof(a));
        scanf("%d",&i);
        while(i!=0) {
            scanf("%c",&c);
            while(c!='\n') {
                scanf("%d",&j);
                a[i][j]=a[j][i]=1;
                scanf("%c",&c);
            }
            scanf("%d",&i);
        }
        ans=0;
        for(i=1; i<=n; i++) {
            ans+=DFS(i);
        }
        printf("%d\n",n-ans);
        scanf("%d",&n);
    }
    return 0;
}
