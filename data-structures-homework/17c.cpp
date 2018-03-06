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

string s;
int cnt['_'+5];
int work(){
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<s.size();i++){
        cnt[s[i]]++;
    }
    if(cnt[s[0]]==s.size())
        return s.size();
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i='0';i<='_';i++){
        if(cnt[i])
            pq.push(cnt[i]);
    }
    int sum=0;
    while(pq.size()>=2){
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        sum+=x+y;
        pq.push(x+y);
    }
    return sum;
}
void pretreat() {
}


bool input() {
}




int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    pretreat();
    input();
    while(cin>>s,s!="END"){
        int ans=work();
        printf("%d %d %.1f\n",s.size()*8,ans,(double)s.size()*8/ans);
    }
    return 0;
}

