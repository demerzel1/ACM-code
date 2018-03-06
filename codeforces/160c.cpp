#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
using ll=long long;
ll n;
ll a[maxn];
ll k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    k--;
    sort(a,a+n);
    ll ind=1;
    ll i;
    for(i=0;i<n;i+=ind){
        for(ind=1;i+ind<n;ind++){
            if(a[i]!=a[i+ind])
                break;
        }
        if(ind*n>k)
            break;
        k=k-ind*n;
    }
    cout<<a[i]<<" "<<a[k/ind];
    return 0;
}
