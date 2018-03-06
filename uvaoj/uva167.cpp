#include<bits/stdc++.h>
using namespace std;

int tsum;
bool vis[3][50];
int T;
int mp[10][10];
bool flag=false;

void eight(int cur,int sum){
    if(cur==9){
        tsum=max(tsum,sum);
//        cout<<"tsum="<<tsum<<"\n";
        return;
    }
    for(int i=1;i<=8;i++){
        if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+8]){
            sum+=mp[cur][i];
//            cout<<sum<<" "<<cur<<" "<<i<<"\n";
            vis[0][i]=vis[1][cur+i]=vis[2][cur-i+8]=true;
            eight(cur+1,sum);
            vis[0][i]=vis[1][cur+i]=vis[2][cur-i+8]=false;
            sum-=mp[cur][i];
        }
    }
    return;
}

int main(){
    cin>>T;
    while(T--){
        tsum=0;
        memset(vis,false,sizeof(vis));
        memset(mp,0,sizeof(mp));
        for(int i=1;i<=8;i++)
            for(int j=1;j<=8;j++)
                cin>>mp[i][j];
        eight(1,0);
        cout<<setw(5)<<tsum<<"\n";
    }
}
