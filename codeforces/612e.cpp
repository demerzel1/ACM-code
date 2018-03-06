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

const int maxn=1000005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a) {
    return a<-eps? -1:a>eps;
}

struct node {
    int v;
    int id;
};
node num[maxn];
int ans[maxn];
vector<node> g[maxn];
bool vis[maxn];
int use[maxn];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>num[i].v;
        num[i].id=i;
    }
    memset(use,-1,sizeof(use));
    memset(ans,-1,sizeof(ans));
    int ind=0;
    for(int i=1; i<=n; i++) {
        if(vis[i])
            continue;
        vis[i]=true;
        int next=num[i].v;
        int now=i;
        int cnt=1;
        g[ind].push_back(num[i]);
        while(now!=next) {
            vis[next]=true;
            g[ind].push_back(num[next]);
            next=num[next].v;
            cnt++;
        }
        if(cnt%2==1) {
            int tt=g[ind][cnt/2].v;
            for(int j=0; j<cnt; j++) {
                ans[g[ind][j].id]=tt;
                tt=num[tt].v;
            }
        } else {
            if(use[cnt]!=-1) {
                int tt=g[use[cnt]][0].id;
                for(int j=0; j<cnt; j++) {
                    ans[g[ind][j].id]=tt;
                    ans[tt]=g[ind][j].v;
                    tt=num[tt].v;
                }
                use[cnt]=-1;
            } else
                use[cnt]=ind;
        }
        ind++;
    }
    bool flag=true;
    for(int i=1; i<=n; i++)
        if(ans[i]==-1) {
            flag=false;
            break;
        }
    if(!flag)
        cout<<-1<<endl;
    else {
        cout<<ans[1];
        for(int i=2; i<=n; i++)
            cout<<' '<<ans[i];
        cout<<endl;
    }
    return 0;
}

/*
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

const int maxn=1000005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a) {
    return a<-eps? -1:a>eps;
}

struct node {
    int v;
    int id;
};
node num[maxn];
int ans[maxn];
vector<node> g[maxn];
bool vis[maxn];
int use[maxn];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>num[i].v;
        num[i].id=i;
    }
    memset(use,-1,sizeof(use));
    memset(ans,-1,sizeof(ans));
    int ind=0;
    for(int i=1; i<=n; i++) {
        if(vis[i])
            continue;
        vis[i]=true;
        int next=num[i].v;
        int now=i;
        int cnt=1;
        g[ind].push_back(num[i]);
        while(now!=next) {
            vis[next]=true;
            g[ind].push_back(num[next]);
            next=num[next].v;
            cnt++;
        }
        if(cnt%2==1) {
            int tt=g[ind][cnt/2].v;
            for(int j=0; j<cnt; j++) {
                ans[g[ind][j].id]=tt;
                tt=num[tt].v;
            }
        } else {
            if(use[cnt]!=-1) {
                vector<int> txhj;
                for(int i=0;i<cnt;i++){
                    txhj.push_back(g[use[cnt]][i].v);
                    txhj.push_back(g[ind][i].v);
                }
//                for(int i=0;i<txhj.size();i++){
//                    cout<<txhj[i]<<' ';
//                }
//                cout<<endl;
                for(int i=0;i<cnt*2;i++){
                    ans[txhj[(i+1)%(cnt*2)]]=txhj[i];
//                    cout<<ans[txhj[(i+1)%(cnt*2)]]<<endl;
                }
                use[cnt]=-1;
            } else
                use[cnt]=ind;
        }
        ind++;
    }
    bool flag=true;
    for(int i=1; i<=n; i++)
        if(ans[i]==-1) {
            flag=false;
            break;
        }
    if(!flag)
        cout<<-1<<endl;
    else {
        cout<<ans[1];
        for(int i=2; i<=n; i++)
            cout<<' '<<ans[i];
        cout<<endl;
    }
    return 0;
}
