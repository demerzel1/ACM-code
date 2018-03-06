#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k;
vector<ll> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            v.push_back(i);
            if(n/i!=i){
                v.push_back(n/i);
            }
        }
    }
    sort(v.begin(),v.end());
    if(v.size()<k)
        cout<<-1<<"\n";
    else{
        cout<<v[k-1]<<"\n";
    }
    return 0;
}