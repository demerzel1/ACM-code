#include<bits/stdc++.h>
using namespace std;

map<string,int> mp;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    n--;
    string s2;
    string s3;
    int cnt1=1,cnt2=0;
    while(n--){
        cin>>s2;
        if(s2==s)
            cnt1++;
        else{
            s3=s2;
            cnt2++;
        }
    }
    if(cnt1>cnt2)
        cout<<s;
    else
        cout<<s3;
    return 0;
}
