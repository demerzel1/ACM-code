#include<bits/stdc++.h>
using namespace std;

int n,m;
bool mp[1005][1005];
bool vis[1005][1005];
int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    while(cin>>n>>m) {
        string s;
        memset(mp,false,sizeof(mp));
        memset(vis,false,sizeof(vis));
        for(int i=1; i<=n; i++) {
            cin>>s;
            for(int j=0; j<m; j++) {
                if(s[j]=='.')
                    mp[i][j+1]=false;
                else if(s[j]=='#')
                    mp[i][j+1]=true;
            }
        }
        int cnt=0;
        for(int i=1; i+1<=n; i+=2) {
            for(int j=1; j+1<=m; j+=2) {
                if((mp[i][j]==false)&&(mp[i+1][j]==false)&&(mp[i][j+1]==false)&&(mp[i+1][j+1]==false)) {
                    cnt++;
//                    cout<<i<<" "<<j<<"\n";
//                    cout<<"cnt++\n";
                    vis[i][j]=vis[i+1][j]=vis[i][j+1]=vis[i+1][j+1]=true;
                }
            }
        }
        int sum=0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(vis[i][j]==false&&mp[i][j]==false)
                    sum++;
            }
        }
//        cout<<cnt<<" cnt\n";
//        cout<<sum<<"\n";
        if(cnt==0) {
            if(sum%2!=0)
                cout<<"first\n";
            else
                cout<<"second\n";
        } else if(cnt%2==0) {
            if(sum%2==0)
                cout<<"second\n";
            else
                cout<<"first\n";
            }else if(cnt==1){
                cout<<"first\n";
            }else{
                if(sum%2!=0)
                    cout<<"second\n";
                else{
                    cout<<"first\n";
                }
            }

    }
    return 0;
}
