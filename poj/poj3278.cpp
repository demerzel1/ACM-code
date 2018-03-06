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
#define maxn 100005
int dx[]= {0,0,-1,1};
int dy[]= {1,-1,0,0};

int n,k;
int s[maxn];
int vis[maxn];
int bfs() {
    queue <int> q;
    q.push(n);
    vis[n]=true;
    s[n]=0;
    while(!q.empty()) {
        int t=q.front();
        q.pop();
        for(int i=0; i<3; i++) {
            int tt=0;
            if(i==0)
                tt=t-1;
            else if(i==1)
                tt=t+1;
            else
                tt=t*2;
            if(tt>100000||tt<0)
                continue;
            if(!vis[tt]) {
                s[tt]=s[t]+1;
                q.push(tt);
                vis[tt]=true;
                if(tt==k)
                    return s[tt];
            }
        }
    }
    return 0;
}

int main() {
    while(cin>>n>>k) {
        memset(vis,0,sizeof(vis));
        if(n>=k) {
            cout<<n-k<<"\n";
        } else
            cout<<bfs()<<"\n";
    }
    return 0;
}
