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


string s;
stack<char> stk;

bool is_left(char c){
    if(c=='<'||c=='{'||c=='['||c=='(')
        return true;
    return false;
}

bool is_match(char c1,char c2){
    if(c1=='<'&&c2=='>')
        return true;
    if(c1=='{'&&c2=='}')
        return true;
    if(c1=='['&&c2==']')
        return true;
    if(c1=='('&&c2==')')
        return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>s;
    int ans=0;
    int sz=s.size();
    for(int i=0;i<sz;i++){
        if(is_left(s[i])){
            stk.push(s[i]);
        }else{
            if(stk.empty()){
                cout<<"Impossible"<<endl;
                return 0;
            }else{
                char c=stk.top();
                if(is_match(c,s[i])){
                    stk.pop();
                }else{
                    ans++;
                    stk.pop();
                }
            }
        }
    }
    if(stk.empty()){
        cout<<ans<<endl;
    }else
        cout<<"Impossible"<<endl;
    return 0;
}
