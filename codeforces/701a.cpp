#include<bits/stdc++.h>
using namespace std;

int a[105];
bool vis[105];
int main(){
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
//    cout<<sum<<"\n";
    sum=sum/(n/2);
//    cout<<sum<<"\n";
    for(int i=1;i<=n;i++){
        if(vis[i])
            continue;
        vis[i]=true;
        cout<<i<<" ";
        for(int j=1;j<=n;j++){
            if(!vis[j]&&a[i]+a[j]==sum){
                vis[j]=true;
                cout<<j<<"\n";
                break;
            }
        }
    }
    return 0;
}
