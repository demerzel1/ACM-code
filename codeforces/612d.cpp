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
inline int sgn(double a) {
    return a<-eps? -1:a>eps;
}



int n,k;
vector<pii> p;
vector<int> ans;

bool cmp(pii a,pii b){
    if(a.first==b.first)
        return a.second>b.second;
    return a.first<b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n>>k;
    for(int i=0; i<n; i++) {
        int t1,t2;
        cin>>t1>>t2;
        p.push_back(make_pair(t1,1));
        p.push_back(make_pair(t2,0));
    }
    sort(p.begin(),p.end(),cmp);
    int cnt=0;
    for(int i=0; i<p.size(); i++) {
//        cout<<p[i].first<<' '<<p[i].second<<endl;
        if(p[i].second) {
            cnt++;
            if(cnt==k)
                ans.push_back(p[i].first);
        } else {
            if(cnt==k)
                ans.push_back(p[i].first);
            cnt--;
        }
    }
    cout<<ans.size()/2<<endl;
    for(int i=0;i<ans.size();i+=2){
        cout<<ans[i]<<' '<<ans[i+1]<<endl;
    }
    return 0;
}
