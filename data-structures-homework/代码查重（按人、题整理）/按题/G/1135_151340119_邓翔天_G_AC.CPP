#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int Rel[200][200];
int Match[200];
bool used[200];
int n,m,k;
int ans;

bool search_e(int x)
{
    for(int i=0;i<m;i++)
    {
        if(!used[i]&&Rel[x][i]==1){
            used[i]=true;
            if(-1==Match[i]||search_e(Match[i])){
                Match[i]=x;
                return true;
            }
        }
    }
    return false;
}

int getmax()
{
    int i,sum=0;
    memset(Match,-1,sizeof(Match));
    for(int i=0;i<n;i++){
        memset(used,false,sizeof(used));
        sum+=search_e(i);
    }
    return sum;
}
int main()
{
    while(EOF!=scanf("%d%d",&n,&m)){
        memset(Rel,-1,sizeof(Rel));
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            Rel[t1-1][t2-1]=1;
        }
        ans=getmax();
        printf("%d\n",ans);
    }
    return 0;
}

