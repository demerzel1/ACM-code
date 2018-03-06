#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
struct Point{
    int z,x,y;
};
Point p,q;
int l,r,c,ans,step[35][35][35],visit[35][35][35];
int d[6][3]={0,0,-1,
0,1,0,
0,0,1,
0,-1,0,
1,0,0,
-1,0,0};
char maze[35][35][35];
bool init(Point& a){
    if(a.z>=0&&a.z<l&&a.x>=0&&a.x<r&&a.y>=0&&a.y<c)
        return 1;
    return 0;
}
void bfs(){
    queue<Point> Q;
    Q.push(p);
    visit[p.z][p.x][p.y]=1;
    while(!Q.empty()){
        p=Q.front();
        if(maze[p.z][p.x][p.y]=='E'){
            ans=step[p.z][p.x][p.y];
            return;
        }
        Q.pop();
        int i;
        for(i=0;i<6;i++){
            q.z=p.z+d[i][0];
            q.x=p.x+d[i][1];
            q.y=p.y+d[i][2];
            if(init(q)&&visit[q.z][q.x][q.y]&&maze[q.z][q.x][q.y]!='#'){
                visit[q.z][q.x][q.y]=1;
                step[q.z][q.x][q.y]=step[p.z][p.x][p.y]+1;
                Q.push(q);
            }
        }
    }
}
int main(){
    int i,j,k;
    while(scanf("%d%d%d",&l,&r,&c)!=EOF,l||r||c){
        for(i=0;i<l;i++)
            for(j=0;j<r;j++)
                for(k=0;k<c;k++){
                    scanf("%c",&maze[i][j][k]);
                    if(maze[i][j][k]=='S'){
                        p.z=i;
                        p.x=j;
                        p.y=k;
                    }
                }
        memset(step,0,sizeof(step));
        memset(visit,0,sizeof(visit));
        ans=0;
        bfs();
        if(ans) cout<<"Escaped in "<<ans<<" minute(s).\n";
        else cout<<"trapped!\n";
    }
    return 0;
}
