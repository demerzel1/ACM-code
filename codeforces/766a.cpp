#include<bits/stdc++.h>
using namespace std;

string a,b;

int main(){
    cin>>a>>b;
    if(a.length()!=b.length())
        cout<<max(a.length(),b.length());
    else{
        if(a==b)
            cout<<-1;
        else
            cout<<a.length();
    }
    return 0;
}
