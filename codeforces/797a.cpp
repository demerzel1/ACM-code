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

template<class T>inline bool read(T&x){
    int c;
    for(c=getchar();~c&&c<33;c=getchar());
    if(!(~c)) return false;
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
    return true;
}

int n,k;

vector<int> ans;
int cnt;

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    if(k==1){
        cout<<n;
        return 0;
    }
    int t=n;
    for(int i=2;i*i<=t;++i){
        if(t%i==0){
            while(t%i==0){
                ans.emplace_back(i);
                cnt++;
                t/=i;
                if(cnt==k-1)
                    break;
            }
            if(cnt==k-1)
                break;
        }
    }
    if(t!=1){
        cnt++;
        ans.emplace_back(t);
    }
    if(cnt==k){
        for(const auto &i:ans){
            cout<<i<<' ';
        }
    } else
        cout<<-1;
    return 0;
}