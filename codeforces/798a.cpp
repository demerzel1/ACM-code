#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int sz=s.size();
    int t=sz/2-1;
    int cnt=0;
    bool flag=true;
    for(int i=0;i<=t;i++){
        if(s[i]!=s[sz-i-1])
            cnt++;
        if(cnt>1){
            flag=false;
            break;
        }
    }
    if(sz%2!=0){
        if(cnt==0||cnt==1)
            cout<<"YES";
    else
        cout<<"NO";
    return 0;
    }
    if(cnt==1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
