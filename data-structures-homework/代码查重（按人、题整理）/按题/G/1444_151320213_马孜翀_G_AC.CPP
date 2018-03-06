#include <iostream>
#include<cstring>

using namespace std;

#define N 110
int useif[N];
int link[N];
int mat[N][N];
int gn,gm;

int can(int t)
{
    int i;
    for(i=1;i<=gm;i++)
    {
        if(useif[i]==0&&mat[t][i])
        {
            useif[i]=1;
            if(link[i]==-1||can(link[i]))
            {
                link[i]=t;
                return 1;
            }
        }
    }
    return 0;
}

int MaxMatch()
{
    int i,num;
    num=0;
    memset(link,0xff,sizeof(link));
    for(i=1;i<=gn;i++)
    {
        memset(useif,0,sizeof(useif));
        if(can(i))num++;
    }
    return num;
}

int main()
{
    while(scanf("%d%d",&gn,&gm)!=EOF)
    {
        memset(mat,0,sizeof(mat));
        int x,y,z;
        scanf("%d",&z);
        for(int i=0;i<z;i++)
        {
            scanf("%d%d",&x,&y);
            mat[x][y]=1;
        }
        printf("%d\n",MaxMatch());
    }
    return 0;
}

