#include<bits/stdc++.h>
using namespace std;
#define maxn 100005

struct edge {
    int ind;
    int u;
    int v;
    int cost;
    int ans;
};

bool comp(const edge& e1,const edge& e2) {
    return e1.cost<e2.cost;
}

bool comp1(const edge& e1,const edge& e2) {
    return e1.ind<e2.ind;
}

struct edge es[maxn];
int V,E;

int par[maxn];
int Rank[maxn];

void init(int n) {
    for(int i=0; i<n; i++) {
        par[i]=i;
        Rank[i]=0;
    }
}

int Find(int x) {
    if(par[x]==x) {
        return x;
    } else {
        return par[x]=Find(par[x]);
    }
}

void unite(int x,int y) {
    x=Find(x);
    y=Find(y);
    if(x==y)
        return;
    if(Rank[x]<Rank[y]) {
        par[x]=y;
    } else {
        par[y]=x;
        if(Rank[x]==Rank[y])
            Rank[x]++;
    }
}

bool same(int x,int y) {
    if(Find(x)==Find(y))
        return true;
    return false;
}

int kruskal() {
    sort(es,es+E,comp);
    init(V);
    int res=0;
    struct edge last_e;
    bool flag=false;
    int ind1=0;
    int t=0;
    for(int i=0; i<E; i++) {
        for(t=1; i+t<E; t++) {
            if(es[i].cost!=es[i+t].cost)
                break;
        }
        for(int j=i; j<i+t; j++) {
            struct edge e=es[i];
            if(!same(e.u,e.v)) {
                //printf("ans u=%d v=%d cost=%d\n",e.u,e.v,e.cost);
                last_e=e;
                ind1=i;
                unite(e.u,e.v);
                res+=e.cost;
                es[i].ans=1;
            } else {
                if(i!=0) {
                    //printf("u=%d v=%d cost=%d\n",e.u,e.v,e.cost);
                    if(last_e.cost==e.cost) {
                        es[ind1].ans=2;
                        es[i].ans=2;
                    }
                }
            }
        }
    }
    return res;
}

int main() {
    cin>>V>>E;
    for(int i=0; i<E; i++) {
        cin>>es[i].u>>es[i].v>>es[i].cost;
        es[i].ind=i;
    }
    kruskal();
    sort(es,es+E,comp1);
    for(int i=0; i<E; i++) {
        if(es[i].ans==0)
            cout<<"none\n";
        else if(es[i].ans==1)
            cout<<"any\n";
        else
            cout<<"at least one\n";
    }
    return 0;
}
