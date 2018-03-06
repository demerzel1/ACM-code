#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=1000005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;

template<class T>inline bool read(T&x){
    int c;
    for(c=getchar();~c&&c<33;c=getchar());
    if(!(~c)) return false;
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
    return true;
}

map<int,int> mp;
int n;
int cnt;
int ans;

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    while(cin>>n){
        mp.clear();
        cnt=0;
        ans=0;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            mp[x]++;
            if(mp[x]>cnt){
                cnt=mp[x];
                ans=x;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}