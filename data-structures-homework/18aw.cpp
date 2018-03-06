#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;
const int N = 10005;

int n;
vector<int> vec[N];
int pre[N];
bool vis[N];
bool root[N];
int u,v;

void Init() {
    for(int i=0; i<N; i++) {
        vec[i].clear();
        pre[i] = i;
        root[i] = true;
        vis[i] = false;
    }
}

void Import() {
    scanf("%d",&n);
    Init();
    for(int i=1; i<n; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        vec[a].push_back(b);
        root[b] = false;
    }
    scanf("%d%d",&u,&v);
}

int Find(int x) {
    if(pre[x] != x)
        pre[x] = Find(pre[x]);
    return pre[x];
}

void Union(int x,int y) {
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    pre[y] = x;
}

void LCA(int par) {
    for(int i=0; i<vec[par].size(); i++) {
        LCA(vec[par][i]);
        Union(par,vec[par][i]);
    }
    vis[par] = true;
    if(par == u && vis[v] == true) {
        printf("%d\n",Find(v));
        return;
    }
    if(par == v && vis[u] == true) {
        printf("%d\n",Find(u));
        return;
    }
}

void solve() {
    int T;
    scanf("%d",&T);
    while(T--) {
        Import();
        for(int i=1; i<=n; i++) {
            if(root[i] == true) {
                LCA(i);
                break;
            }
        }
    }
}

int main() {
    solve();
    return 0;
}
