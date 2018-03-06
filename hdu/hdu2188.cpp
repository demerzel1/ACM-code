#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        if(n%(m+1)==0)
            cout<<"Rabbit\n";
        else
            cout<<"Grass\n";
    }
    return 0;
}
