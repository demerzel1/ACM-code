#include<bits/stdc++.h>
using namespace std;
bool vis[100005];
int tans;
int ans;
int main(){
    int n;
    cin>>n;
    int x;
    for(int i=0;i<2*n;i++){
        cin>>x;
        if(!vis[x]){
            vis[x]=true;
            tans++;
            ans=max(ans,tans);
        }else{
            tans--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
