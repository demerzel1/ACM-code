#include<bits/stdc++.h>
using namespace std;

int a[5][5],ans;
char b[10];
int dx[]={-2,-2,-1,1,2,2,1,-1};
int dy[]={-1,1,2,2,1,-1,-2,-2};
int biaozhun[5][5]={{1,1,1,1,1},
                  {0,1,1,1,1},
                  {0,0,-1,1,1},
                  {0,0,0,0,1},
                  {0,0,0,0,0}};
void dfs(int x,int y,int n){
    int i,j,p,num,nx,ny;
    int t;
    if(memcmp(a,biaozhun,sizeof(biaozhun))==0){
        if(n<ans)
            ans=n;
        return;
    }
    if(n==9){
        t=a[x][y];
        a[x][y]=a[2][2];
        a[2][2]=t;
        if(memcmp(a,biaozhun,sizeof(biaozhun))==0&&10<ans)
            ans=10;
        a[2][2]=a[x][y];
        a[x][y]=t;
        return;
    }
    p=0;
    for(i=0;i<5;i++)
        for(j=i;j<5;j++)
            if(a[i][j]==0)
                p++;
    if(p-2>10-n)
        return;
    for(i=0;i<8;i++){
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx>=0&&nx<5&&ny>=0&&ny<5){
            t=a[x][y];
            a[x][y]=a[nx][ny];
            a[nx][ny]=t;
            dfs(nx,ny,n+1);
            a[nx][ny]=a[x][y];
            a[x][y]=t;
        }
    }
}
int main(){
    int x,y,N;
    scanf("%d",&N);
    getchar();
    while(N--){
        int i,j;
        for(i=0;i<5;i++){
            gets(b);
            for(j=0;j<5;j++){
                if(b[j]==' '){
                    a[i][j]=-1;
                    x=i;
                    y=j;
                }
                else
                    a[i][j]=b[j]-'0';
            }
        }
        ans=11;
        dfs(x,y,0);
        if(ans<11)
            printf("Solvable in %d move(s).\n",ans);
        else
            printf("Unsolvable in less than 11 move(s).\n");
    }
    return 0;
}
