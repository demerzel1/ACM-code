#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n;
vector<pair<int,int> > v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int _,__;
    for(int i=0;i<n;i++){
        cin>>_>>__;
        v.emplace_back(_,__);
    }
    sort(v.begin(),v.end());
    int ans=-1;
    for(int i=0;i<n;i++){
        if(v[i].second>=ans){
            ans=v[i].second;
        } else
            ans=v[i].first;
    }
    cout<<ans<<endl;
    return 0;
}