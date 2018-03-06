#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define MAX 105
int dx[8]={0,0,-1,1,-1,1,-1,1};
int dy[8]={1,-1,0,0,1,1,-1,-1};
char oil[MAX][MAX];

void dfs(int x,int y){
    if(oil[x][y]=='@'){
        oil[x][y]='*';
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                dfs(x+dx[i],y+dy[i]);
            }
        }
    }
}

int main(){
    int m,n;
    while(1){
        int cnt=0;
        scanf("%d%d",&m,&n);
        if(m==0&&n==0) break;
        getchar();
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                scanf("%c",&oil[i][j]);
            }
            getchar();
        }
        for(int i=0;i<=m+1;i++){
            oil[i][0]='*';
            oil[i][n+1]='*';
        }
        for(int j=0;j<=n+1;j++){
            oil[0][j]='*';
            oil[m+1][j]='*';
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(oil[i][j]=='@'){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",cnt);
//        for(int i=0;i<=m+1;i++){
//            for(int j=0;j<=n+1;j++){
//                printf("%c",oil[i][j]);
//            }
//            printf("\n");
//        }
    }
    return 0;
}
