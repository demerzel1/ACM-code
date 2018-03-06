#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt1=0;
    int cnt2=0;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a>b)
            cnt1++;
        if(a<b)
            cnt2++;
    }
    if(cnt1>cnt2)
        cout<<"Mishka";
    else if(cnt1==cnt2)
        cout<<"Friendship is magic!^^";
    else
        cout<<"Chris";
    return 0;
}
