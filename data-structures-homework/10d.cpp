#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
#define maxn 55
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int nk[]={3,2,0,1};
bool a[maxn][maxn];

int main(){
    int N,n,r,x,y;
    scanf("%d",&N);
    while(N--){
        scanf("%d%d",&n,&r);
        memset(a,0,sizeof(a));
        for(int i=0;i<r;i++){
            scanf("%d%d",&x,&y);
            a[x][y]=1;
        }
        scanf("%d%d",&x,&y);
        int k;
        if(x==0) k=0;
        if(x==n+1) k=1;
        if(y==0) k=2;
        if(y==n+1) k=3;
        while(1){
            x=x+dx[k];
            y=y+dy[k];
            if(x==0||x==n+1||y==0||y==n+1) break;
            if(a[x][y]) k=nk[k];
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}
