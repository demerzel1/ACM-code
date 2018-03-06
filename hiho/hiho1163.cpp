#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int t=0;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        t^=x;
    }
    if(t==0)
        cout<<"Bob\n";
    else
        cout<<"Alice\n";
    return 0;
}
