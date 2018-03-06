#include<bits/stdc++.h>
using namespace std;

map<char,int> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string str;
    cin>>str;
    int ans=0;
    for(int i=0;i<2*n-2;i+=2){
        mp[str[i]-32]++;
        if(mp[str[i+1]]<=0){
            ans++;
        }else{
            mp[str[i+1]]--;
        }
    }
    cout<<ans;
    return 0;
}
