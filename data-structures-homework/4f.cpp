#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define N 105
#define clr(a) memset(a,0,sizeof(a))

int rr[]={1,1,0,-1,-1,-1,0,1};
int cc[]={0,1,1,1,0,-1,-1,-1};
char g[N][N];
int vis[N][N];
int cnt;

void dfs(int r,int c){
    if(g[r][c]!='W'||vis[r][c]) return;
    cnt++;
    vis[r][c]=1;
    for(int k=0;k<8;k++)
        dfs(r+rr[k],c+cc[k]);
}

int main(){
    int T,i,x,y;
    char s[N];
    scanf("%d",&T);
    getchar();
    getchar();
    for(int t=1;t<=T;t++){
        i=0;
        if(t!=1)
            puts("");
        while(gets(s)&&strlen(s)){
            if(s[0]=='L'||s[0]=='W')
                strcpy(g[i++],s);
            else{
                sscanf(s,"%d%d",&x,&y);
                clr(vis);
                cnt=0;
                dfs(x-1,y-1);
                printf("%d\n",cnt);
            }
        }
    }
    return 0;
}

