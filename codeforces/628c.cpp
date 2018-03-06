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

const int maxn=100005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a){return a<-eps? -1:a>eps;}

int n;
string s;
int k;
char ans[maxn];
int cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n>>k;
    cin>>s;
    int sz=s.size();
    for(int i=0;i<sz;i++)
        ans[i]=s[i];
    bool flag=false;
    for(int i=0;i<sz;i++){

        int tt=k-cnt;
        int ta=s[i]-'a';
        int tz='z'-s[i];
        int tmax=max(ta,tz);
        if(tt<=tmax){
            if(ta==tmax){
                ans[i]=s[i]-tt;
                flag=true;
                break;
            }else{
                ans[i]=s[i]+tt;
                flag=true;
                break;
            }
        }else{
            if(ta==tmax){
                ans[i]='a';
                cnt+=tmax;
            }else{
                ans[i]='z';
                cnt+=tmax;
            }
        }
    }
    if(!flag){
        cout<<-1<<endl;
    }else
        cout<<ans<<endl;
    return 0;
}
