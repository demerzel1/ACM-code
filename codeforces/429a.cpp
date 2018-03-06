#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
vector<int> G[maxn];
int now[maxn];
int expect[maxn];
int odd = 0;
int even = 0;
int ans = 0;
bool vis[maxn];
vector<int> ansnum;
void dfs(int v, int level) {
    vis[v] = true;
    bool flag = false;
    if (level % 2 == 0) {
        if ((now[v] + even) % 2 == expect[v]) {
            for (int i = 0; i < G[v].size(); i++) {
                if (!vis[G[v][i]])
                    dfs(G[v][i], level + 1);
            }
        } else {
            flag = true;
            //    printf("now[v]=%d even=%d expectv=%d\n",now[v],even,expect[v]);
            //    printf("v=%d level=%d even++\n",v,level);
            ans++;
            even++;
            ansnum.push_back(v);
            for (int i = 0; i < G[v].size(); i++) {
                if (!vis[G[v][i]])
                    dfs(G[v][i], level + 1);
            }
        }
    } else {
        if ((now[v] + odd) % 2 == expect[v]) {
            for (int i = 0; i < G[v].size(); i++) {
                if (!vis[G[v][i]])
                    dfs(G[v][i], level + 1);
            }
        } else {
            flag = true;
            //     printf("now[v]=%d odd=%d expectv=%d\n",now[v],odd,expect[v]);
            //    printf("v=%d level=%d odd++\n",v,level);
            ans++;
            odd++;
            ansnum.push_back(v);
            for (int i = 0; i < G[v].size(); i++) {
                if (!vis[G[v][i]])
                    dfs(G[v][i], level + 1);
            }
        }
    }
    if (level % 2 == 0 && flag) {
        even--;
    } else if (level % 2 != 0 && flag) {
        odd--;
    }
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &now[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &expect[i]);
    }
    dfs(1, 1);
    printf("%d\n", ans);
    for (int i = 0; i < ansnum.size(); i++)
        printf("%d\n", ansnum[i]);
    return 0;
}
