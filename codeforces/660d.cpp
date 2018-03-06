#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <iomanip>
#include <set>
#include <climits>
#include <ctime>
#include <complex>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
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

vector<pii> v;
int n;
map<pii,int> mp;
int ans;

bool cmp(pii a,pii b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n;
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
//            cout<<v[j].first<<' '<<v[j].second<<' '<<v[i].first<<' '<<v[i].second<<endl;
            pii t=make_pair(v[j].first-v[i].first,v[j].second-v[i].second);
//            cout<<t.first<<' '<<t.second<<'\n';
            ans+=mp[t];
            mp[t]++;
        }
    }
    cout<<ans/2<<endl;
    return 0;
}
