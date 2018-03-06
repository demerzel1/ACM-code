#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    bool flag=false;
    int ans;
    cin>>a>>b>>c>>d;
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            if(i*a-j*c==d-b){
                flag=true;
                ans=b+i*a;
                break;
            }
        }
        if(flag)
            break;
    }
    if(flag)
        cout<<ans<<"\n";
    else
        cout<<-1<<"\n";
    return 0;
}
