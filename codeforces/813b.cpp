#include <bits/stdc++.h>
 
using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int maxn=200005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
 
template<class T>inline void read(T&x){
    int c;
    for(c=getchar();c<32&&~c;c=getchar());
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
}
 
ll x,y,l,r;
 
vector<ll> xx,yy,ss;
set<ll> s;
 
int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>x>>y>>l>>r;
    int cnt1=0,cnt2=0;
    ll _r=r;
    while(_r){
        cnt1++;
        _r/=x;
    }
    _r=r;
    while(_r){
        cnt2++;
        _r/=y;
    }
    ll t=1;
    for(int i=0;i<cnt1;i++){
        xx.emplace_back(t);
        t*=x;
    }
    t=1;
    for(int i=0;i<cnt2;i++){
        yy.emplace_back(t);
        t*=y;
    }
    for(const auto &i:xx){
        for(const auto &j:yy){
            if(!s.count(i+j)&&(i+j)<=r&&(i+j)>=l){
                ss.emplace_back(i+j);
                s.insert(i+j);
            }
 
        }
    }
    ll ans=0;
    sort(ss.begin(),ss.end());
    for(int i=0;i<ss.size();i++){
       // cout<<ss[i]<<endl;
        if(i==0){
            ans=max(ans,ss[i]-l);
        }else{
            ans=max(ans,ss[i]-ss[i-1]-1);
        }
        if(i==ss.size()-1){
            ans=max(ans,r-ss[i]);
        }
    }
    if(ss.empty()){
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}