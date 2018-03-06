#include<cstdio>
#include<iostream>
using namespace std;
char str[300][300];
int dx[]={-1,-1,0,0,1,1};
int dy[]={-1,0,-1,1,0,1};

bool dfsw(int x,int y,int limit){
    if(x==0||y==0||x>limit||y>limit) return false;
    if(y==limit&&str[x][y]=='w') return true;
    if(str[x][y]!='w') return false;
    str[x][y]='.';
    for(int i=0;i<6;i++){
        if(dfsw(x+dx[i],y+dy[i],limit)) return true;
    }
    return false;
}

int main(){
    int t=1;
    while(true){
        int n;
        cin>>n;
        if(n==0) return 0;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>str[i][j];
        }
        printf("%d ",t++);
        int f=1;
        for(int i=1;i<=n;i++){
            if(str[i][1]=='w'){
                if(dfsw(i,1,n)){
                    puts("W");
                    f=0;
                    break;
                }
            }
        }
        if(f)
            puts("B");
    }
    return 0;
}
