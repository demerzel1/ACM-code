#include<bits/stdc++.h>
using namespace std;
int target[5][5]={{1,1,1,1,1},{0,1,1,1,1},
{0,0,-1,1,1},{0,0,0,0,1},{0,0,0,0,0}};
int a[5][5],ans;
char b[10];
int dx[]={-2,-2,-1,1,2,2,1,-1};
int dy[]={-1,1,2,2,1,-1,-2,-2};
void dfs(int x,int y,int n)
{
    int i,j,k,p,num,newx,newy;
    if(memcmp(a,target,sizeof(target))==0)
    {
        if(n<ans)
            ans=n;
        return;
    }
    if(n==9)
    {
        p=abs(x-2)+abs(y-2);
        if(p!=3)
            return;
        k=a[x][y];
        a[x][y]=a[2][2];
        a[2][2]=k;
        if(memcmp(a,target,sizeof(target))==0&&10<ans)
            ans=10;
        a[2][2]=a[x][y];
        a[x][y]=k;
        return;
    }
    p=0;
    for(i=0;i<5;i++)
        for(j=i;j<5;j++)
            if(a[i][j]==0)
                p++;
    if(p-2>10-n)
        return;
    for(i=0;i<8;i++)
    {
        newx=x+dx[i];
        newy=y+dy[i];
        if(newx>=0&&newx<5&&newy>=0&&newy<5)
        {
            k=a[x][y];
            a[x][y]=a[newx][newy];
            a[newx][newy]=k;
            dfs(newx,newy,n+1);
            a[newx][newy]=a[x][y];
            a[x][y]=k;
        }
    }
}
int main()
{
    int i,j,k,x,y,N,t;
    gets(b);
    sscanf(b,"%d",&N);
    while(N--)
    {
        for(i=0;i<5;i++)
        {
            gets(b);
            for(j=0;j<5;j++)
            {
                if(b[j]==' ')
                {
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
