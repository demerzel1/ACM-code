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
inline int sgn(double a) {
    return a<-eps? -1:a>eps;
}


#define Max 2000005
bool prime[Max];
void IsPrime() {
    prime[0]=prime[1]=0;
    prime[2]=1;
    for(int i=3; i<Max; i++)
        prime[i]=i%2==0?0:1;
    int t=(int)sqrt(Max*1.0);
    for(int i=3; i<=t; i++)
        if(prime[i])
            for(int j=i*i; j<Max; j+=2*i)
                prime[j]=0;
}

int n;
int a[maxn];
map<int,int> mp;
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    IsPrime();
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a,a+n);
    if(mp[1]>1) {
        int ind=0;
        while(a[ind]==1&&ind<n) ind++;
        if(ind==n) {
            for(int i=0; i<n; i++)
                ans.push_back(1);
        } else {
            for(int i=0; i<ind; i++)
                ans.push_back(1);
            for(int i=ind; i<n; i++) {
                if(prime[a[i]+1]) {
                    ans.push_back(a[i]);
                    break;
                }
            }
        }
    } else {
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(prime[a[i]+a[j]]) {
                    ans.push_back(a[i]);
                    ans.push_back(a[j]);
                    break;
                }
            }
            if(ans.size()!=0)
                break;
        }
        if(ans.size()==0) {
            for(int i=0; i<n; i++) {
                if(prime[a[i]]) {
                    ans.push_back(a[i]);
                    break;
                }
            }
        }
    }
    if(ans.size()==0){
        ans.push_back(a[0]);
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<' ';
    }
    return 0;
}
