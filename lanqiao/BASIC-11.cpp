#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    long long n=0;
    int l=s.size();
    long long p=1;
    for(int i=l-1;i>=0;i--){
        if(s[i]>='A'&&s[i]<='F'){
            int x=s[i]-'A'+10;
            n+=x*p;
            p*=16;
        }else{
            int x=s[i]-'0';
            n+=x*p;
            p*=16;
        }
    }
    cout<<n;
    return 0;
}
