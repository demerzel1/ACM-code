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
typedef pair<int,int>ii;
const int maxn=200005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int n,m;
int a[maxn];
int p[maxn];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ind=n-1;
    for(int i=0;i<n;i++){
        p[i]=i;
    }
    while(ind>=0){
        int tind=ind;
        while(tind>=0&&a[tind]==a[ind])
            tind--;
        for(int i=tind+1;i<=ind;i++)
            p[i]=tind;
        ind=tind;
    }
    int l,r,x;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&l,&r,&x);
        l--;
        r--;
        ind=r;
        int ans=-1;
        while(ind>=l){
            if(a[ind]==x){
                ind=p[ind];
            }else{
                ans=ind+1;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
