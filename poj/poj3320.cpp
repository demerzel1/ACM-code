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

const int maxn=1000005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int n;
int a[maxn];
map<int,int> mp;
int sum=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    while(cin>>n){
        for(int i=1; i<=n; i++) {
            cin>>a[i];
            if(mp[a[i]]==0) {
                sum++;
                mp[a[i]]=1;
            }
        }
        mp.clear();
        int l=1,r=1,ans=n;
        int cnt=0;
        while(r<=n) {
            while(cnt<sum&&r<=n) {
                if(mp[a[r]]==0) {
                    cnt++;
                    mp[a[r]]=1;
                } else
                    mp[a[r]]++;
                r++;
            }
            if(cnt==sum) {
                ans=min(ans,r-l);
                while(l<=r&&cnt==sum) {
                    mp[a[l]]--;
                    if(mp[a[l]]==0)
                        cnt--;
                    l++;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
