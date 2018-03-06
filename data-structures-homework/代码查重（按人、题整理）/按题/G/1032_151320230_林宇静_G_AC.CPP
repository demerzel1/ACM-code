#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int girl[110],coulde[11000][2],n,m,x,y,sum,k;
bool temp[110][110],boy[110];
bool Find(int x)
{
    for(int i=1;i<=m;i++){
        if(temp[x][i]&&!boy[i]){
            boy[i]=true;
            if(girl[i]==-1||Find(girl[i])){
                girl[i]=x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        sum=0;
        memset(girl,-1,sizeof(girl));
        memset(temp,false,sizeof(temp));
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            scanf("%d%d",&x,&y);
            temp[x][y]=true;
        }
        for(int i=1;i<=n;i++){
            memset(boy,false,sizeof(boy));
            if(Find(i))
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}

