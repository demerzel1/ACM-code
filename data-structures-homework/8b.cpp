#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
#define maxn 500005
int n,aa[maxn],c[maxn];

struct Node{
   int v;
   int order;
}in[maxn];

int lb(int x){
    return x&(-x);
}

int getsum(int x){
    int i,t=0;
    for(i=x;i>=1;i-=lb(i)){
        t+=c[i];
    }
    return t;
}
void update(int t,int value){
    int i;
    for(i=t;i<=n;i+=lb(i)){
        c[i]+=value;
    }
}
bool cmp(Node a,Node b){
    return a.v<b.v;
}

int main(){
    int i,j;
    while(scanf("%d",&n)==1&&n){
        for(i=1;i<=n;i++){
            scanf("%d",&in[i].v);
            in[i].order=i;
        }
        sort(in+1,in+n+1,cmp);
        for(i=1;i<=n;i++) aa[in[i].order]=i;
        memset(c,0,sizeof(c));
        long long ans=0;
        for(i=1;i<=n;i++)
        {
            update(aa[i],1);
            ans+=i-getsum(aa[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
