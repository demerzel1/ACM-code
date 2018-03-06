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
 
int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    while(~scanf("%s",s)){
        int sz=strlen(s);
        int ans1=0;
        int ans2=0;
        for(int i=0;i<sz;i++){
            ans1=(ans1*10+s[i]-'0')%73;
            ans2=(ans2*10+s[i]-'0')%137;
        }
        printf("Case #%d: ",cas);
        cas++;
        if(ans1%73==0&&ans2%137==0){
            printf("YES\n");
        } else
            printf("NO\n");
    }
    return 0;
}