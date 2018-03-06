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

const int maxn=300005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int n;
int a[maxn];
map<int,int> mp;
vector<pii> ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int l=1;
    int i;
    for(i=1;i<=n;i++){
        if(mp[a[i]]==1){
            mp.clear();
            ans.push_back(make_pair(l,i));
            l=i+1;
        }else{
            mp[a[i]]++;
        }
    }
    if(ans.size()==0){
        cout<<-1<<endl;
    }else{
        if(ans[ans.size()-1].second!=n){
            ans[ans.size()-1].second=n;
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<' '<<ans[i].second<<endl;
        }
    }
    return 0;
}
