#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
using namespace std;
#define MAXN 210
#define MAXM 40010 //#define MAXM 210*210 UVA±‡“Îæπ»ª±®¥Ì°£°£°£

struct node
{
    double x, y;
}a[MAXN], b[MAXN];

struct Edge
{
    int v, next;
}edge[MAXM];

int n, m, s, v;
int cnt;

int first[MAXN], link[MAXN];
bool vis[MAXN];


void init()
{
    cnt = 0;
    memset(first, -1, sizeof(first));
    memset(link, -1, sizeof(link));
}

double dist(const node a, const node b)
{
    cout<<sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))<<endl;
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));

}

int ED(int u)
{
    for(int e = first[u]; e != -1; e = edge[e].next)
    {
        int v = edge[e].v;
        if(!vis[v])
        {
            vis[v] = true;
            if(link[v] == -1 || ED(link[v]))
            {
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}

void read_graph(int u, int v)
{
    edge[cnt].v = v;
    edge[cnt].next = first[u], first[u] = cnt++;
}

void read_graph2()
{
    for(int i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &a[i].x, &a[i].y);
    }
    for(int i = 1; i <= m; i++)
    {
        scanf("%lf%lf", &b[i].x, &b[i].y);
    }
    double dis = s*v;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            double temp = dist(a[i], b[j]);
            if(temp <= dis) read_graph(i, j);
        }
    }
}

void solve()
{
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if(ED(i)) ans++;
    }
    printf("%d\n", n-ans);
}

int main()
{
    while(~scanf("%d%d%d%d", &n, &m, &s, &v))
    {
        init();
        read_graph2();
        solve();
    }
    return 0;
}
