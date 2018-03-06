#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct edge
{
    int from;
    int to;
    int weight;
}Edge;

bool cmp(Edge a,Edge b){return a.weight<b.weight;}
Edge e_t[1000*999/2+9];
Edge e_o[1000*999/2+9];
Edge e_spe[1200];
int parent_s[1100];
int n,m;
    int sum=0;
int union_find(int x)
{
    if(x==parent_s[x]) return x;
    else parent_s[x]=union_find(parent_s[x]);
    return parent_s[x];
}

void kruskal()
{
    int pt_n=n-1;

    sort(e_t,e_t+m,cmp);
    for(int i=0;i<m;i++)
    {
        int ta=union_find(e_t[i].from);
        int tb=union_find(e_t[i].to);
        if(ta==tb) continue;
        parent_s[ta]=tb;
        sum+=e_t[i].weight;
        pt_n--;
        if(pt_n=0) break;
    }
    return ;
}

///checking the critical
int parent_spe[1200];
bool vis_spe[1200];
bool flag=true;
int union_find_special(int x)
{
    if(x==parent_spe[x]) return x;
    else parent_spe[x]=union_find_special(parent_spe[x]);
    return parent_spe[x];
}
void spe_check()
{
    flag=true;
    int sum_t=0;
    for(int i=1;i<=n;i++) parent_spe[i]=i;
    ///initial complete
    for(int i=0;i<n-1;i++){
        Edge t_e=e_spe[i];
        int ta=union_find_special(t_e.from);
        int tb=union_find_special(t_e.to);
        //cout<<t_e.from<<" "<<t_e.to<<endl;
        //cout<<ta<<" "<<tb<<endl;
        if(ta==tb){flag=false;break;}
        parent_spe[ta]=tb;
        //cout<<union_find_special(t_e.from)<<" "<<t_e.from<<endl;
        //cout<<union_find_special(t_e.to)<<" "<<t_e.to<<endl;
        sum_t+=t_e.weight;
        //cout<<t_e.weight<<endl;
    }
   //cout<<sum_t<<endl;
    if(flag&&sum_t>sum) flag=false;
    return;
}
///

int main()
{
    while(EOF!=scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++) {parent_s[i]=i;}
        for(int i=0;i<m;i++)
        {
            int t1,t2,t3;
            Edge temp;
            scanf("%d%d%d",&temp.from,&temp.to,&temp.weight);
            e_t[i]=temp;
            e_o[i]=temp;
        }
        sum=0;
        kruskal();
        //cout<<sum<<endl;
        for(int i=0;i<n-1;i++){
            int t1;
            scanf("%d",&t1);
            e_spe[i]=e_o[t1-1];
        }
        spe_check();
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

