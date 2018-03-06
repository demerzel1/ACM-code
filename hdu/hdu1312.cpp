#include<bits/stdc++.h>
using namespace std;

char data[22][22];
int w,h;
int dx[]= {1,0,-1,0};
int dy[]= {0,1,0,-1};
int cnt=0;
void dfs(int a,int b) {
    cnt++;
    data[a][b] = '#';
 //   printf("a=%d b=%d\n",a,b);
    for(int i = 0; i<4; i++) {
        int x = a+dx[i];
        int y = b+dy[i];
        if(x<h && y<w && x>=0 && y>=0 && data[x][y] == '.')
            dfs(x,y);
    }
    return;
}

int main() {
  //  freopen("in.txt", "r", stdin);
    while(scanf("%d%d",&w,&h)!=EOF) {
        cnt=0;
        if(w==0&&h==0)
            break;
        getchar();
        int mx,my;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                scanf("%c",&data[i][j]);
                if(data[i][j]=='@') {
                    mx=i;
                    my=j;
         //           printf("mx=%d my=%d\n",mx,my);
                }
            }
            getchar();
        }
        dfs(mx,my);
        printf("%d\n",cnt);
    }
    return 0;
}
