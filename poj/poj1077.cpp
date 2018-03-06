#include<bits/stdc++.h>
using namespace std;
char mp[5][5];
char ans[10005];
int x,y;

void swup

int main(){
    memset(mp,0,sizeof(mp));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            scanf("%d",&mp[i][j]);
            if(mp[i][j]=='x'){
                x=i;
                y=j;
            }

    }

    return 0;
}
