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
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

int main(){
    int n;
    string s;
    int p,q;
    cin>>n>>p>>q;
    cin>>s;
    int sz=s.size();
    for(int i=0;i<=100;i++){
        if(i*p>n){
            cout<<-1<<endl;
            return 0;
        }
        if((n-i*p)%q==0){
            int t=(n-i*p)/q;
            cout<<i+t<<endl;
            int ind=0;
            for(int j=0;j<i;j++){
                for(int k=0;k<p;k++){
                    putchar(s[ind]);
                    ind++;
                }
                cout<<endl;
            }
            for(int j=0;j<t;j++){
                for(int k=0;k<q;k++){
                    putchar(s[ind]);
                    ind++;
                }
                cout<<endl;
            }
            return 0;
        }
    }
    return 0;
}
