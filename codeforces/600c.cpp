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
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=200005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

char str[maxn];
char ans[maxn];
int cnt[30];
int main(){
    string s;
    cin>>s;
    int sz=s.size();
    for(int i=0;i<sz;i++)
        cnt[s[i]-'a']++;
    int r=25;
    int ind=0;
    for(int i=0;i<26;i++){
        if(cnt[i]%2!=0){
            while(cnt[r]%2==0&&i<r)
                r--;
            if(i==r){
                ans[sz/2]='a'+i;
                cnt[i]--;
            }else{
                cnt[i]++;
                cnt[r]--;
            }
        }
        for(int j=0;j<cnt[i]/2;j++){
            ans[ind]=ans[sz-ind-1]='a'+i;
            ind++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
