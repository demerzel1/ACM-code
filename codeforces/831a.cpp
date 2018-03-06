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

const int maxn=105;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a) {
    return a<-eps? -1:a>eps;
}

int n;
int a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int flag=0;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=1; i<n; i++) {
        if(flag==0) {
            if(a[i]>a[i-1])
                continue;
            if(a[i]==a[i-1]) {
                flag=1;
                continue;
            } else {
                flag=3;
                continue;
            }
        } else if(flag==1) {
            if(a[i]==a[i-1])
                continue;
            if(a[i]>a[i-1]) {
                cout<<"NO";
                return 0;
            }
            if(a[i]<a[i-1]) {
                flag=3;
                continue;
            }
        } else if(flag==3) {
            if(a[i]<a[i-1])
                continue;
            else {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}
