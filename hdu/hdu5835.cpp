#include <bits/stdc++.h>
 
using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int maxn=15;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
 
template<class T>inline void read(T&x){
    int c;
    for(c=getchar();c<32&&~c;c=getchar());
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
}
 
int cas=1;
 
int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int mx=0;
        int sum=0;
        int x;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            mx=max(x,mx);
            sum+=x;
        }
        int ans=0;
        int les=sum-mx;
        if(mx>les*3+2)
            ans=les*2+1;
        else
            ans=sum/2;
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}