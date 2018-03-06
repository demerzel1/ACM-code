#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
typedef long long ll;
int a[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll ans=0;
    ll tans=1;
    int cnt=0;
    for(int i=n-1;i>=1;i--){
        if(a[i]-a[i-1]<=1){
            tans*=a[i-1];
            cnt++;
            i--;
        }
        if(cnt==2){
            ans+=tans;
            cnt=0;
            tans=1;
        }
    }
    cout<<ans;
    return 0;
}
