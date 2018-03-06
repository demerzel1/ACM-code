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
#include<climits>
using namespace std;
#define maxn 10005

typedef struct edge {
    int to;
    int length;
    edge(int a,int b){
        to=a;
        length=b;
    }
}edge;

int N,K;
vector<edge> G[maxn];

bool centroid[maxn];
int subtree_size[maxn];

int ans;

int compute_subtree_size(int v,int p){
    int c=1;
    int sz=G[v].size();
    for(int i=0;i<sz;i++){
        int w=G[v][i].to;
        if(w==p||centroid[w])
            continue;
        c+=compute_subtree_size(G[v][i].to,v);
    }
    subtree_size[v]=c;
    return c;
}

pair<int,int> search_centroid(int v,int p,int t){
    pair<int,int> res=make_pair(INT_MAX,-1);
    int s=1,m=0;
    int sz=G[v].size();
    for(int i=0;i<sz;i++){
        int w=G[v][i].to;
        if(w==p||centroid[w])
            continue;
        res=min(res,search_centroid(w,v,t));
        m=max(m,subtree_size[w]);
        s+=subtree_size[w];
    }
    m=max(m,t-s);
    res=min(res,make_pair(m,v));
    return res;
}

void enumerate_paths(int v,int p,int d,vector<int> &ds){
    ds.push_back(d);
    int sz=G[v].size();
    for(int i=0;i<sz;i++){
        int w=G[v][i].to;
        if(w==p||centroid[w])
            continue;
        enumerate_paths(w,v,d+G[v][i].length,ds);
    }
}

int count_pairs(vector<int> &ds){
    int res=0;
    sort(ds.begin(),ds.end());
    int j=ds.size();
    for(int i=0;i<ds.size();i++){
        while(j>0&&ds[i]+ds[j-1]>K) --j;
        res+=j-(j>i?1:0);
    }
    j=ds.size();
    for(int i=0;i<ds.size();i++){
        while(j>0&&ds[i]+ds[j-1]>=K) --j;
        res-=j-(j>i?1:0);
    }
    return res/2;
}

void solve_subproblem(int v){
    compute_subtree_size(v,-1);
    int s=search_centroid(v,-1,subtree_size[v]).second;
    centroid[s]=true;

    for(int i=0;i<G[s].size();i++){
        if(centroid[G[s][i].to])
            continue;
        solve_subproblem(G[s][i].to);
    }

    static vector<int> ds;
    ds.clear();
    ds.push_back(0);
    for(int i=0;i<G[s].size();i++){
        if(centroid[G[s][i].to])
            continue;

        static vector<int> tds;
        tds.clear();
        enumerate_paths(G[s][i].to,s,G[s][i].length,tds);

        ans-=count_pairs(tds);
        ds.insert(ds.end(),tds.begin(),tds.end());
    }
    ans+=count_pairs(ds);
    centroid[s]=false;
}

void solve(){
    ans=0;
    solve_subproblem(0);
    if(ans>0)
        printf("AYE\n");
    else
        printf("NAY\n");
}

int main(){
    while(scanf("%d",&N)&&N){
        for(int i=0;i<N;i++)
            G[i].clear();
        int x,x1;
        for(int i=0;i<N;i++){
            while(true){
                scanf("%d",&x);
                if(x==0)
                    break;
                scanf("%d",&x1);
                x--;
                G[i].push_back(edge(x,x1));
                G[x].push_back(edge(i,x1));
            }
        }
        while(scanf("%d",&K)&&K){
            solve();
        }
        printf(".\n");
    }
    return 0;
}

