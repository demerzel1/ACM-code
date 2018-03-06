#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
using ll=long long;

pair<ll,ll> p[maxn];
int n;
ll l_max[maxn];
ll l_min[maxn];
ll r_max[maxn];
ll r_min[maxn];

bool judge(ll m){
    int ind=1;
    for(int i=1;i<n;i++){
        while(ind+1<=n&&p[ind+1].first-p[i].first<=m)
            ind++;
        if(max(l_max[i-1],r_max[ind+1])-min(l_min[i-1],r_min[ind+1])<=m)
            return true;
    }
    return false;
}

ll b_search(ll l,ll r){
    if(l==r)
        return l;
    ll m=(l+r)>>1;
    if(judge(m))
        return b_search(l,m);
    else
        return b_search(m+1,r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        p[i].first=x+y;
        p[i].second=x-y;
    }
    sort(p+1,p+n+1);
    l_max[0]=l_max[n+1]=r_max[0]=r_max[n+1]=LLONG_MIN;
    l_min[0]=l_min[n+1]=r_min[0]=r_min[n+1]=LLONG_MAX;
    for(int i=1;i<=n;i++){
        l_min[i]=min(l_min[i-1],p[i].second);
        l_max[i]=max(l_max[i-1],p[i].second);
    }
    for(int i=n;i>0;i--){
        r_min[i]=min(r_min[i+1],p[i].second);
        r_max[i]=max(r_max[i+1],p[i].second);
    }
    cout<<setiosflags(ios::fixed)<<setprecision(8)<<1.0*b_search(0,10000000000ll)/2;
    return 0;
}
