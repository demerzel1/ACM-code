#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> p;

int main() {
    in  n;
    cin>>n;
    p.clear();
    for(int i=n; i>0; i--) {
        if(!p[i]) {
            int len=(int)log2(i)+1;
            ll maxn=(1<<len)-1;
            p[i]=maxn^i;
            p[maxn^i]=i;
        }
    }
    ll sum=0;
    for(int i=0; i<=n; i++) {
        sum+=p[i]^i;
    }
    cout<<sum<<endl;
    for(int i=0; i<=n; i++) {
        printf("%d ",p[i]);
    }
    return 0;
}
