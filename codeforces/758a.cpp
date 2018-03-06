#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans;
int a[100005];
int maxa=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
        maxa=max(maxa,x);
    }
    for(int i=0;i<n;i++){
        ans+=abs(maxa-a[i]);
    }
    cout<<ans;
    return 0;
}
