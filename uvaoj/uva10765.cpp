#include<bits/stdc++.h>
using namespace std;
#define maxn 10005

typedef struct node{
    int index;
    int cnt;
}node;

bool cmp(node a,node b){
    if(a.cnt>b.cnt)
        return true;
    else if(a.cnt==b.cnt){
        if(a.index<b.index)
            return true;
    }
    return false;
}

int n,m;
vector<int> g[maxn];
int dfn[maxn];
int low[maxn];
bool status[maxn];
int iscut[maxn];
bool instack[maxn];
int stk[maxn];
int top;
int belong[maxn];
int qlt;
vector<int> bcc[maxn];
node ans[maxn];

void init(){
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(dfn));
    for(int i=0;i<maxn;i++){
        g[i].clear();
//        ans[i].index=i;
//        ans[i].cnt=0;
    }
    memset(stk,0,sizeof(stk));
    memset(status,false,sizeof(status));
    memset(instack,false,sizeof(instack));
    memset(iscut,false,sizeof(iscut));
    memset(belong,0,sizeof(belong));
    qlt=0;
    top=0;
}

void tarjan(int c,int d,int from){
//    printf("vis c=%d d=%d\n",c,d);
    int child=0;
    stk[++top]=c;
    instack[c]=true;
    status[c]=true;
    dfn[c]=low[c]=d;
    int sz=g[c].size();
    int v;
    for(int i=0;i<sz;i++){
        v=g[c][i];
        if(!status[v]){
            child++;
            tarjan(v,d+1,c);
            low[c]=min(low[c],low[v]);
            if(c!=0&&low[v]>=dfn[c]){
//                printf("cut %d\n",c);
                iscut[c]++;
            }
        }
        else if(instack[v]&&v!=from){
//            printf("v=%d c=%d\n",v,c);
            low[c]=min(low[c],dfn[v]);
        }
        if(c==0&&child>1){
            iscut[c]=1;
        }
    }
//    printf("c=%d dfn=%d low=%d\n",c,dfn[c],low[c]);
//    if(dfn[c]==low[c]){
//        qlt++;
//        printf("qlt=%d c=%d top=%d\n",qlt,c,top);
//        printf("stack:\n");
//        for(int i=1;i<=top;i++){
//            printf("%d ",stk[i]);
//        }
//        printf("\n");
//        while(true){
//            v=stk[top--];
//            instack[v]=false;
//            belong[v]=qlt;
//       //     printf("qlt=%d v=%d\n",qlt,v);
//            bcc[qlt].push_back(v);
//            if(v==c)
//                break;
//        }
//    }
    return;
}
int main(){
    while(scanf("%d%d",&n,&m)&&(n!=0&&m!=0)){
        init();
        int a,b;
        while(scanf("%d%d",&a,&b)&&(a!=-1&&b!=-1)){
            g[a].push_back(b);
            g[b].push_back(a);
        }
        tarjan(0,1,-1);
//        printf("qlt=%d\n",qlt);
        for(int i=0;i<n;i++){
            ans[i].index=i;
            ans[i].cnt=iscut[i]+1;
        }
//        for(int i=1;i<=qlt;i++){
//            int sz=bcc[i].size();
//            printf("sz=%d i=%d\n",sz,i);
//            for(int j=0;j<sz;j++){
//                int v=bcc[i][j];
//                printf("bcc i=%d j=%d v=%d\n",i,j,v);
//                if(iscut[v]){
//              //      printf("anscnt++ %d\n",v);
//                    ans[v].cnt++;
//                }
//            }
//        }
        sort(ans,ans+n,cmp);
        for(int i=0;i<m;i++){
            printf("%d %d\n",ans[i].index,ans[i].cnt);
        }
        printf("\n");
    }
    return 0;
}
