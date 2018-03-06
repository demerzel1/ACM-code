#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n){
        map<int,int> mp;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            mp[x]++;
        }
        int ans=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second>=(n+1)/2){
                ans=it->first;
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
