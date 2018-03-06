#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int n;
    while(scanf("%d",&n)){
        if(n==-1)
            break;
        ll male=0,female=1;
        for(int i=0;i<n;i++){
            ll t=female;
            female=male+1;
            male+=t;
    //        cout<<male<<" "<<female<<"\n";
        }
        cout<<male<<" "<<female+male<<"\n";
    }
    return 0;
}
