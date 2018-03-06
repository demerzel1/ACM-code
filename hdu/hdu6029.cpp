#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int x;
        int cnt=0;
        for(int i=2;i<=n;i++){
            cin>>x;
            if(x==1)
                if(cnt<=i-2)
                    cnt+=2;
        }
        if(cnt==n)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
