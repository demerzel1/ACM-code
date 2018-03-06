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

const int maxn=500005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a){return a<-eps? -1:a>eps;}

int n;
int a[maxn];
int b[maxn];
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]!=a[i+1]){
            int tans=0;
            int pre=a[i];
            int j;
            for(j=i;j<n;j++){
                if(a[j]==a[j+1])
                    break;
            }
            int len=j-i+1;
            if(len%2==0){
                int lst=a[j];
                int mid=(i+j)>>1;
                for(int k=i;k<=mid;k++)
                    b[k]=pre;
                for(int k=mid+1;k<=j;k++)
                    b[k]=lst;
                tans=(len-1)/2;
            }else{
                for(int k=i;k<=j;k++){
                    b[k]=pre;
                }
                tans=len/2;
            }
            i=j;
            ans=max(ans,tans);
        }else
            b[i]=a[i];
    }
    b[n]=a[n];
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}
