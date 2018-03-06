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
typedef long long ll;

#define maxn 505

struct point{
    int num;
    int cnt;
    point(int n,int c){
        num=n;
        cnt=c;
    }
};
typedef struct point point;
vector<point> g[maxn];
bool flag;
int status[maxn];
int low[maxn];
int dfn[maxn];
int top;
int f,r;
int lcnt=1;
int par[maxn];
int sta[maxn];
bool instack[maxn];
int qlt;
int belong[maxn];
int degree[maxn];

void tarjan(int c,int d){
   // printf("vis c=%d d=%d\n",c,d);
    status[c]=1;
    dfn[c]=low[c]=d;
    sta[++top]=c;
    instack[c]=true;
    int sz=g[c].size();
    int v;
    for(int i=0;i<sz;i++){
        v=g[c][i].num;
     //   printf("vis v=%d\n",v);
        if(status[v]==0){
         //   printf("sta=0 vis %d\n",v);
            par[v]=g[c][i].cnt;
       //     printf("parv=%d\n",par[v]);
            tarjan(v,d+1);
            low[c]=min(low[c],low[v]);
        }else if(instack[v]&&par[c]!=g[c][i].cnt){
    //        printf("instack vis=%d\n",v);
            low[c]=min(low[c],dfn[v]);
        }
    }
    //printf("c=%d dfn=%d low=%d\n",c,dfn[c],low[c]);
    if(dfn[c]==low[c]){
      //  printf("c=%d\n",c);
        qlt++;
        while(true){
            v=sta[top--];
       //     printf("v=%d\n",v);
            instack[v]=false;
            belong[v]=qlt;
            if(v==c)
                break;
        }
    }
}

int solve(){
    tarjan(1,1);
    for(int i=1;i<=f;i++){
        int sz=g[i].size();
        for(int j=0;j<sz;j++){
            int v=g[i][j].num;
            if(belong[v]!=belong[i])
                degree[belong[i]]++;
        }
    }
    int sum=0;
    for(int i=1;i<=qlt;i++){
      //  printf("degree %d = %d\n",i,degree[i]);
        if(degree[i]==1)
            sum++;
    }
    return sum;
}

int main(){
    while(scanf("%d%d",&f,&r)!=EOF){
        int a,b;
        for(int i=0;i<r;i++){
            scanf("%d%d",&a,&b);
            g[a].push_back(point(b,lcnt));
            g[b].push_back(point(a,lcnt++));
        }
        int sum=solve();
     //   printf("%d\n",sum);
        int ans=(sum+1)/2;
        printf("%d\n",ans);
    }
    return 0;
}
