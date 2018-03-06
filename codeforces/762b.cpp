#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define endl "\n"

int a,b,c;
int m;
vector< pair<ll,string> > v;
int ans;
ll ans1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b>>c;
    cin>>m;
    ll _;
    string _1;
    for(int i=0;i<m;i++){
        cin>>_>>_1;
        v.push_back(make_pair(_,_1));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<m;i++){
        if(a>0&&v[i].second=="USB"){
            a--;
            ans++;
            ans1+=v[i].first;
            continue;
        }
        if(b>0&&v[i].second=="PS/2"){
            b--;
            ans++;
            ans1+=v[i].first;
            continue;
        }
        if(c>0){
            c--;
            ans++;
            ans1+=v[i].first;
        }
        if(a==0&&b==0&&c==0){
            break;
        }
    }
    cout<<ans<<' '<<ans1<<endl;
    return 0;
}