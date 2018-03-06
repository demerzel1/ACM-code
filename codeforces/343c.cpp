#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 100005
int n,m;
ll h[maxn],p[maxn];
bool ok(ll time) {
    ll need;
    int pos=0;
    for(int i=0; i<n; i++) {
        if(abs(h[i]-p[pos])>time)
            continue;
        if(h[i]==p[pos])
            pos++;
        if(h[i]>p[pos]) {
            need=max(h[i]+time-2*(h[i]-p[pos]),h[i]+(time-(h[i]-p[pos]))/2);
        } else
            need=h[i]+time;
        while(p[pos]<=need&&pos<=m)
            pos++;
    }
    return pos>m-1;
}

int main() {
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>h[i];
    for(int i=0; i<m; i++)
        cin>>p[i];
    ll l=-1;
    ll r=abs(h[0]-p[0])*2+abs(h[0]-p[m-1]);
//    cout<<r<<endl;
    ll mid;
    while(l+1<r) {
        mid=(l+r)>>1;
        //  cout<<"mid="<<mid<<endl;
        if(ok(mid))
            r=mid;
        else
            l=mid;
    }
    cout<<r<<endl;
    return 0;
}
