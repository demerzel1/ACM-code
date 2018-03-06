#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

char ar[500][500];
int vis[500][500];
int pri[200];
int c[200];

int T,n,m,i,j,k,l,cnt,p,tc=0;
void dfs(int i,int j,int k){
    if(i>n||i<1||j>m||j<1||vis[i][j]==1||ar[i][j]!=(char)k)
        return;
    vis[i][j]=1;
    dfs(i,j-1,k);
    dfs(i,j+1,k);
    dfs(i-1,j,k);
    dfs(i+1,j,k);
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>ar[i][j];

    printf("World #%d\n",++tc);
    l=1;
    for(k=0;k<26;k++){
        memset(&vis,0,sizeof vis);
        cnt=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(vis[i][j]==0&&ar[i][j]==k+97){
                    cnt++;
                    dfs(i,j,k+97);
                }
            }
        }
        pri[k]=k;
        c[k]=cnt;
    }
    for(i=0;i<26;i++){
        for(j=26-1;j>i;j--){
            if(c[j]>c[i]){
                swap(c[j],c[i]);
                swap(pri[j],pri[i]);
            }
            else if(c[j]==c[i]&&pri[i]>pri[j]){
                swap(pri[j],pri[i]);
            }
        }
    }
    for(i=0;i<26;i++){
        if(c[i]!=0)
            printf("%c: %d\n",pri[i]+97,c[i]);
    }
    memset(pri,0,sizeof pri);
    memset(c,0,sizeof c);
    }
    return 0;
}
