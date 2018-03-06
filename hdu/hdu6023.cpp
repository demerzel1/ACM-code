#include<bits/stdc++.h>
using namespace std;

int timu[1500];
bool vis[1500];

int main(){
    int T;
    cin>>T;
    while(T--){
        for(int i=1000;i<=1015;i++){
            timu[i]=0;
            vis[i]=0;
        }
        int cnt=0;
        int ans=0;
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            int t1,t2;
            cin>>t1;
            getchar();
            cin>>t2;
            string b;
            cin>>b;
            if(vis[x]==true)
                continue;
            if(b=="AC"){
                ans+=timu[x];
                ans+=t1*60+t2;
                vis[x]=true;
                cnt++;
            }else{
                timu[x]+=20;
            }
        }
        cout<<cnt<<" "<<ans<<"\n";
    }
    return 0;
}
