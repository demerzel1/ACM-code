#include <bits/stdc++.h>
 
using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
 
const int maxn=10000005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
 
template<class T>inline void read(T&x){
    int c;
    for(c=getchar();c<32&&~c;c=getchar());
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
}
 
char s[maxn];
int cas=1;
bool vis[35];
 
int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int ans=0;
        scanf("%s",s);
        memset(vis,false,sizeof(vis));
        int sz=strlen(s);
        for(int i=0;i<sz;i++){
            if(!vis[s[i]-'a']){
                ans++;
                vis[s[i]-'a']=true;
            }
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}