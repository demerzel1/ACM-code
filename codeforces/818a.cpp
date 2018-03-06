#include <iostream>

using namespace std;
using ll=long long;
ll n,k;

int main(){
    cin>>n>>k;
    ll t=n/2;
    ll tt=t/(k+1);
    if(tt==0){
        cout<<0<<' '<<0<<' '<<n<<endl;
    }else{
        cout<<tt<<' '<<k*tt<<' '<<n-tt*(k+1)<<endl;
    }
    return 0;
}