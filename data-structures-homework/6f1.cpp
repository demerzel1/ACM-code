#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=100;
const int cx[]={-1,1,0,0,0,0};
const int cy[]={0,0,-1,1,0,0};
const int cz[]={0,0,0,0,1,-1};

int l,r,c;
char M[maxn][maxn][maxn];
struct Node{
    int z,x,y;
    int step;
};

queue<Node> Q;
int ans;
int vis[maxn][maxn][maxn];

void bfs(){
    while(!Q.empty()){
        Node tem=Q.front();
        Q.pop();
        int x=tem.x;
        int y=tem.y;
        int z=tem.z;
        int cnt=tem.step;
        for(int i=0;i<6;i++){
            int tx=x+cx[i];
            int ty=y+cy[i];
            int tz=z+cz[i];
            if(M[tz][tx][ty]=='.'){
                Q.push(Node{tz,tx,ty,cnt+1});
                M[tz][tx][ty]='#';
            }
            else if(M[tz][tx][ty]=='E'){
                ans=cnt+1;
                break;
            }
        }
        if(ans!=-1)
            break;
    }
}

int main(){
    while(scanf("%d%d%d",&l,&r,&c)){
        if(l==0&&r==0&&c==0)
            break;
        memset(M,-1,sizeof(M));
        while(!Q.empty()) Q.pop();
        for(int i=1;i<=l;i++)
            for(int j=1;j<=r;j++){
                scanf("%s",M[i][j]+1);
                for(int k=1;k<=c;k++){
                    if(M[i][j][k]=='S')
                    Q.push(Node{i,j,k,0});
                }
            }
        ans=-1;
        bfs();
        if(ans==-1){
            printf("Trapped!\n");
        }
        else{
            printf("Escaped in %d minute(s).\n",ans);
        }

    }
    return 0;
}
