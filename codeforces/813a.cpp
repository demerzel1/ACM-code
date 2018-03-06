#include <bits/stdc++.h>
 
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
 
template<class T>inline void read(T&x){
    int c;
    for(c=getchar();c<32&&~c;c=getchar());
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
}
 
int n;
int sum;
int m;
vector<pii> v;
 
 
int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        sum+=x;
    }
    cin>>m;
    int _,_1;
    for(int i=0;i<m;i++){
        cin>>_>>_1;
        v.emplace_back(_,_1);
    }
  //  sort(v.begin(),v.end());
   // cout<<sum<<endl;
    for(const auto &i:v){
        if(sum>=i.first&&sum<=i.second){
            cout<<sum<<endl;
            return 0;
        }
        if(sum<i.first){
            cout<<i.first<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}