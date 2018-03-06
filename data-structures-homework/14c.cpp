#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int x,y;
}node;

int L,n,m;
int useif[105];
int link[105];
node pl[105];
node pi[105];
node line[105][2];
int biao[105][105];
void input(){
    scanf("%d%d",&n,&m);
    scanf("%d%d",&pl[0].x,&pl[0].y);
    int j=0;
    for(int i=1;i<n;i++,j++){
        scanf("%d%d",&pl[i].x,&pl[i].y);
        line[j][0]=pl[i-1];
        line[j][1]=pl[i];
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&pi[i].x,&pi[i].y);
    }
}

double dis(node a,node b){
    double d=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return d;
}

void init(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++)
        if(dis(line[i][0],pi[j])+dis(line[i][1],pi[j])-2*dis(line[i][0],line[i][1])<1e-20){
            biao[i][j]=1;
        }
    }
//    for(int i=0;i<n-1;i++){
//        for(int j=0;j<m;j++)
//            printf("%d ",biao[i][j]);
//    cout<<endl;
//    }

}

int can(int t)
{
    int i;
    for(i=0;i<m;i++){
       if(useif[i]==0 &&biao[t][i]==1)
       {
           useif[i]=1;


	  if(link[i]==-1 || can(link[i])){
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
    memset(link,-1,sizeof(link));
    for(i=0;i<n-1;i++)
    {
      memset(useif,0,sizeof(useif));
        if(can(i))
            num++;
    }
return num;
}



int main(){
    scanf("%d",&L);
    while(L--){
        memset(pl,0,sizeof(pl));
        memset(pi,0,sizeof(pi));
        memset(biao,0,sizeof(biao));
        memset(line,0,sizeof(line));
        input();
        init();
        int ans=MaxMatch()+n;
        printf("%d\n",ans);
        for(int i=0;i<n-1;i++){
            printf("%d %d ",line[i][0].x,line[i][0].y);
            for(int j=0;j<m;j++){
                if(link[j]==i){
                    printf("%d %d ",pi[j].x,pi[j].y);
                }
            }
        }
        printf("%d %d\n\n",line[n-2][1].x,line[n-2][1].y);
    }
    return 0;
}
