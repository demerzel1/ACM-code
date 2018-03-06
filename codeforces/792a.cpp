#include <iostream>
#include <algorithm>
#include <map>
#include <climits>

using ll=long long;
using namespace std;
const int maxn =200005;

int n;
ll a[maxn];
map<ll,int> mp;
ll ans=LLONG_MAX;
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n;i++){
        mp[a[i]-a[i-1]]++;
        ans=min(ans,a[i]-a[i-1]);
    }
    cout<<ans<<' '<<mp[ans]<<endl;
    return 0;
}