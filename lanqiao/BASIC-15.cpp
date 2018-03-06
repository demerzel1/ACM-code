#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    if(a.length()!=b.length())
        cout<<1;
    else if(a==b)
        cout<<2;
    else{
        bool flag=true;
        for(int i=0;i<a.length();i++){
            if(a[i]==b[i]||abs(a[i]-b[i])==32){
                continue;
            }else{
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<3;
        else
            cout<<4;
    }
    return 0;
}
