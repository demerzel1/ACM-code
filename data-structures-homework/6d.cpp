#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<map>
using namespace std;

int n,f,g;
string s[27];
int dx[]={0,-1,-1,-1,0,1,1,1};
int dy[]={1,1,0,-1,-1,-1,0,1};

void dfs(int x,int y){
    s[x][y]='0';
    for(int k=0;k<8;k++){
        f=x+dx[k];
        g=y+dy[k];
        if((f>=0&&f<n)&&(g>=0&&g<n)&&s[f][g]!='0')
            dfs(f,g);
    }
}

int main(){
    int cs=1;
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>s[i];
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='1'){
                    res++;
                    dfs(i,j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",cs++,res);
    }
    return 0;
}
