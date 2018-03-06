#include<bits/stdc++.h>
using namespace std;

int cnt[500];

int main(){
    string s;
    getline(cin,s);
    int sz=s.size();
    for(int i=0;i<sz;i++){
        cnt[s[i]]++;
    }
    cnt[' ']=500;
    string s1;
    getline(cin,s1);
    sz=s1.size();
    bool f=false;
    for(int i=0;i<sz;i++){
        cnt[s1[i]]--;
        if(cnt[s1[i]]<0){
            f=true;
            break;
        }
    }
    if(f)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
