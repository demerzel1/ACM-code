#include<bits/stdc++.h>
using namespace std;

map<char,int> mp;

int main(){
    string s;
    cin>>s;
    int sz=s.size();
    for(int i=0;i<sz;i++)
        mp[s[i]]++;
    int ans=0;
    for(int i=0;i<26;i++){
        if(mp[i+'a']%2!=0)
            ans++;
    }
    if(ans%2!=0||ans==0)
        cout<<"First\n";
    else
        cout<<"Second\n";
    return 0;
}
