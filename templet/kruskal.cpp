#include<bits/stdc++.h>
using namespace std;

int N,M;
int fa[maxn];

struct edge{
    int x,y,w;
    edge(int x=0,int y=0,int w=0):x(x),y(y),w(w){}
}e[maxm];

bool cmp(edge a,edge b){
    return a.w<b.w;
}

int getfather(int x){
    if(x==fa[x])
        return x;
    else
        return fa[x]=getfather(fa[x]);
}
int kruscal(){
    int ans=0;
    sort(e+1,e+M+1,cmp);
    int cnt=N;
    for(int i=1;i<=N;i++)
        fa[i]=i;
    for(int i=1;i<=M;i++){
        int t1=getfather(e[i].x);
        int t2=getfather(e[i].y);
        if(t1!=t2){
            fa[t1]=t2;
            ans+=e[i].w;
            if(cnt==1)
                break;
        }
    }
    return ans;
}
