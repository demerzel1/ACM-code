#include <bits/stdc++.h>
#define eps 1e-6
#define LL long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
using namespace std;

const int MAXN = 3010;
int n, m;
vector<int> G[MAXN];
int dist[MAXN][MAXN];
bool vis[MAXN];
pii s[MAXN][3], e[MAXN][3];
void updateS(int u, int v) {
    s[u][2] = s[u][1];
    s[u][1] = s[u][0];
    s[u][0] = mp(v, dist[u][v]);
}
void updateE(int u, int v) {
    if(dist[u][v] > e[v][0].second) {
        e[v][2] = e[v][1];
        e[v][1] = e[v][0];
        e[v][0] = mp(u, dist[u][v]);
    } else if(dist[u][v] > e[v][1].second) {
        e[v][2] = e[v][1];
        e[v][1] = mp(u, dist[u][v]);
    } else if(dist[u][v] > e[v][2].second)
        e[v][2] = mp(u, dist[u][v]);
}
void bfs(int st) {
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    q.push(st);
    vis[st] = true;
    dist[st][st] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if(vis[v]) continue;
            dist[st][v] = dist[st][u] + 1;
            vis[v] = true;
            updateS(st, v);
            updateE(st, v);
            q.push(v);
        }
    }
}
bool check(int u, int v, int num1, int num2) {
    int node[4] = {u, v, e[u][num1].first, s[v][num2].first};
    if(e[u][num1].first == 0 || s[v][num2].first == 0) return false;
    for(int i = 0; i < 4; i++) {
        for(int j = i+1; j < 4; j++)
            if(node[i] == node[j]) return false;
    }
    return true;
}
int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
        bfs(i);
    int ans = 0;
    int node[4];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j || dist[i][j] == 0) continue;
            for(int k1 = 0; k1 < 3; k1++) {
                for(int k2 = 0; k2 < 3; k2++) {
                    if(!check(i, j, k1, k2)) continue;
                    if(e[i][k1].second+dist[i][j]+s[j][k2].second > ans) {
                        node[0] = e[i][k1].first;
                        node[1] = i;
                        node[2] = j;
                        node[3] = s[j][k2].first;
                        ans = e[i][k1].second+dist[i][j]+s[j][k2].second;
                    }
                }
            }
        }
    }
    for(int i = 0; i < 4; i++)
        printf("%d ", node[i]);
    return 0;
}



/*
#include<bits/stdc++.h>
using namespace std;
#define maxn 3010

struct node {
    int dis;
    int index;
    bool friend operator < (node a, node b) {
        if(a.dis==b.dis)
            return a.index < b.index;
        return a.dis<b.dis;
    }
};

int n,m;
vector<int> mp[maxn];
struct node p[maxn][maxn];
struct node p1[maxn][maxn];
struct node p2[maxn][maxn];
bool vis[maxn];
int far[2][maxn];
int far1[2][maxn];
void bfs(int s) {
    queue<int> q;
    q.push(s);
    int len=0;
    vis[s]=true;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        if(!q.empty())
            len=(len+1)%q.size();
        else
            len++;
        int sz=mp[u].size();
        for(int i=0; i<sz; i++) {
            if(mp[u][i]==s)
            continue;
            if(!vis[mp[u][i]]) {
                vis[mp[u][i]]=true;
//                cout<<"u="<<u<<"v="<<mp[u][i]<<"\n";
                p[s][mp[u][i]].dis=len;
                p[s][mp[u][i]].index=mp[u][i];
//                p1[mp[u][i]][s].dis=len;
//                p1[mp[u][i]][s].index=s;
                p2[s][mp[u][i]].dis=len;
                p2[s][mp[u][i]].index=mp[u][i];
                q.push(mp[u][i]);
            }else if(len>p[s][mp[u][i]].dis){
                p[s][mp[u][i]].dis=len;
                p[s][mp[u][i]].index=mp[u][i];
//                p1[mp[u][i]][s].dis=len;
//                p1[mp[u][i]][s].index=s;
                p2[s][mp[u][i]].dis=len;
                p2[s][mp[u][i]].index=mp[u][i];
            }
        }
    }
    return;
}

int main() {
    cin>>n>>m;
    int u,v;
    for(int i=0; i<m; i++) {
        cin>>u>>v;
        mp[u].push_back(v);
    }
    for(int i=1; i<=n; i++) {
        memset(vis,false,sizeof(vis));
        bfs(i);
//        cout<<i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<p[i][j].dis<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(p[i][j].dis){
                p1[p[i][j].index][i].dis=p[i][j].dis;
                p1[p[i][j].index][i].index=i;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        sort(p[i]+1,p[i]+n+1);
        far[0][i]=p[i][n].index;
        far[1][i]=p[i][n].dis;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<p1[i][j].dis<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(int i=1; i<=n; i++) {
        sort(p1[i]+1,p1[i]+n+1);
        far1[0][i]=p1[i][n].index;
        far1[1][i]=p1[i][n].dis;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<p1[i][j].index<<" ";
        }
        cout<<"\n";
    }
    int sum=INT_MIN;
    int a=0,b=0,c=0,d=0;
    cout<<"t=13:\n";
                cout<<far1[1][2]<<" "<<p2[2][8].dis<<" "<<far[1][8]<<"\n";
                cout<<far1[0][2]<<" "<<2<<" "<<8<<" "<<far[0][8]<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!p2[i][j].dis)
                continue;
            int t=far1[1][i]+far[1][j]+p2[i][j].dis;
            if(t==9){
                cout<<"t=11:\n";
                cout<<far1[1][i]<<" "<<p2[i][j].dis<<" "<<far[1][j]<<"\n";
                cout<<far1[0][i]<<" "<<i<<" "<<j<<" "<<far[0][j]<<"\n";
            }
            if(t>sum&&(far1[0][i]!=far[0][j])&&(far1[0][i]!=j)&&(far[0][j]!=i)){
                sum=t;
                a=far1[0][i];
                b=i;
                c=j;
                d=far[0][j];
            }
        }
    }
    cout<<sum<<"\n";
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
    return 0;
}
*/
