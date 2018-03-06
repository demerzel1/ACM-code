#pragma warning (disable:4996)
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
#include <ctime>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const double EPS = 1e-9;
const double PI = 2 * asin(1);
const int INF = 0x7fffffff;
const LL LINF = 0x7fffffffffffffff;


map<LL,int> mp;
int t;
void pretreat() {}
int input() {
    scanf("%d",&t);
    getchar();
    for(int i=0; i<t; i++) {
        long long a;
        char c;
        c=getchar();
        getchar();
        cin>>a;
        getchar();
        long long x=0;
        long long t=1;
        //   printf("%c",c);
        //   cout<<" "<<a<<endl;
        while(a) {
            x+=(a%10%2)*t;
            t*=10;
            a/=10;
        }
        if(c=='+')
            mp[x]++;
        if(c=='-')
            mp[x]--;
        if(c=='?')
            printf("%d\n",mp[x]);
    }
}

void solve() {

}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    input();
    pretreat();
    solve();
    return 0;
}
