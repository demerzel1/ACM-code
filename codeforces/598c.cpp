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
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int>ii;
const int INF=0x7f7f7f7f;
const ld PI=acos(-1.0);
const ld EPS=1e-9;
inline int sgn(ld a){return a<-EPS? -1:a>EPS;}

vector<pair<ld,int> > v;
ld ans_angle;
int ans_ind1;
int ans_ind2;

int main(){
    int n;
    cin>>n;
    int ind=1;
    for(int i=0;i<n;i++){
        ld x,y;
        cin>>x>>y;
        pair<ld,int> angle;
        angle.first=atan2(y,x);
        angle.second=ind++;
        v.push_back(angle);
    }
    ans_angle=2*PI;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        ld tans=v[(i+1)%n].first-v[i].first;
        if(sgn(tans)==-1)
            tans+=2*PI;
        if(tans<ans_angle){
            ans_angle=tans;
            ans_ind1=v[i].second;
            ans_ind2=v[(i+1)%n].second;
        }
    }
    cout<<ans_ind1<<" "<<ans_ind2<<"\n";
    return 0;
}
