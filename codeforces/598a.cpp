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
typedef long long ll;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll n;
        cin>>n;
        ll sum=(n+1)*n/2;
        ll t=1;
        while(t<=n){
            sum-=2*t;
            t*=2;
          //  cout<<sum<<"\n";
        }
        cout<<sum<<"\n";
    }
    return 0;
}
