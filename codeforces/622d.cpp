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
const int maxn=1000005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int ans[maxn];

int main(){
    int n;
    cin>>n;
    if(n%2==0){
        int ind=1;
        for(int i=1;i<n;i+=2){
            ans[ind]=i;
            ans[n-ind+1]=i;
            ind++;
        }
        ind=n+1;
        for(int i=2;i<n;i+=2){
            ans[ind]=i;
            ans[3*n-ind]=i;
            ind++;
        }
        ans[3*n/2]=ans[2*n]=n;
    }else{
        int ind=1;
        for(int i=1;i<n;i+=2){
            ans[ind]=i;
            ans[n-ind+1]=i;
            ind++;
        }
        ind=n+1;
        for(int i=2;i<n;i+=2){
            ans[ind]=i;
            ans[3*n-ind]=i;
            ind++;
        }
        ans[n/2+1]=ans[2*n]=n;
    }
    for(int i=1;i<=2*n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
