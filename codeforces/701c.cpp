#include<bits/stdc++.h>
using namespace std;

map<char,int> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int sz=s.size();
    int l=0;
    int ans=INT_MAX;
    for(int i=0;i<sz;i++){
        mp[s[i]]++;
        int temp=mp[s[i]];
        while(mp[s[l]]>1){
            mp[s[l]]--;
            l++;
        }
        if(temp==1)
            ans=i-l+1;
        else{
            ans=min(ans,i-l+1);
        }
    }
    cout<<ans;
    return 0;
}
