#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
class point{
public:
    int x;
    int y;
    point(int a=0,int b=0){
        x=a;
        y=b;
    }
    bool friend operator == (point a, point b){return (a.x == b.x) && (a.y == b.y);}
};
int board[8][8]={0};
int dx[8]={1,-1,2,2,1,-1,-2,-2};
int dy[8]={2,2,1,-1,-2,-2,1,-1};
int main(){
    char x1,y1,x2,y2;
    while(scanf("%c%c",&x1,&y1)!=EOF){
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++){
                board[i][j]=-1;
            }
        point a,b;
        a.y=x1-'a';
        a.x=y1-'1';
        board[a.x][a.y]=0;
        getchar();
        scanf("%c%c",&x2,&y2);
        getchar();
        b.y=x2-'a';
        b.x=y2-'1';
        board[b.x][b.y]=0;
        queue<point> q;
        q.push(a);
        point s,ns;
        while(!q.empty()){
            s=q.front();
            q.pop();
            if(s==b){
                break;
            }else{
                for(int i=0;i<8;i++){
                    ns=point(s.x+dx[i],s.y+dy[i]);

                    if((0<=ns.x)&&(ns.x<8)&&(0<=ns.y)&&(ns.y<8)){
                        if(board[ns.x][ns.y]<=0){

                            board[ns.x][ns.y]=board[s.x][s.y]+1;
                            q.push(ns);

                        }
                    }
                }
            }

        }
     printf("%d %d %d %d\n",x1,y1,x2,y2);
        printf("To get from %c%c to %c%c takes %d knight moves.\n",x1,y1,x2,y2,board[b.x][b.y]);

    }
    return 0;
}
