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
inline int sgn(double a){return a<-eps? -1:a>eps;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    string s;
    cin>>s;
    int sz=s.size();
    for(int i=0;i<sz;i++){
        if(i==0)
            continue;
        if(s[i]==s[i-1]){
            for(int j=0;j<26;j++){
                if(('a'+j)!=s[i-1]&&('a'+j)!=s[i+1]){
                    s[i]='a'+j;
                   // cout<<i<<endl;
                    break;
                }
            }
        }
    }
    cout<<s<<endl;
    return 0;
}
