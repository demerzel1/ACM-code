#include<bits/stdc++.h>
using namespace std;

int main(){
    long long l,r,k;
    cin>>l>>r>>k;
    bool flag=false;
    long long ans=1;
    while(ans<=r){
        if(ans>=l){
            if(!flag){
                flag=true;
                cout<<ans;
            }
            else{
                cout<<" "<<ans;
            }
        }
        if(ans>(r/k))
            break;
        ans*=k;
    }
    if(flag==0)
        cout<<-1;
    return 0;
}
