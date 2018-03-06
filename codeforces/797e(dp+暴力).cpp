#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=100005;
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

int n;
int a[maxn];
int q;

int gao (int p, int k);

int dp[100005][505];

void init(){
    for(int i=n;i>=1;--i){
        for(int j=1;j<=500;++j){
          //  cout<<i<<' '<<j<<endl;
            if(i+a[i]+j>n){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=dp[i+a[i]+j][j]+1;
            }
        }
    }
}

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    init();
   // cout<<111;
    cin>>q;
    int p,k;
    for(int i=1;i<=q;++i){
        cin>>p>>k;
        if(k<=500)
            cout<<dp[p][k]<<'\n';
        else{
            int ans=gao(p,k);
            cout<<ans<<'\n';
        }
    }
    return 0;
}

int gao (int p, int k) {
    int cnt=0;
    while(p<=n){
        cnt++;
        p+=a[p]+k;
    }
    return cnt;
}