#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define maxm 2000010
int N,M;
int fa[maxn];
int mp[1005][1005];
int ind=1;
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

int main(){
    int T;
    scanf("%d",&T);
    int cas=0;
    while(T--){
        cas++;
        ind=1;
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&mp[i][j]);
                if(j>1){
                    e[ind].x=(i-1)*m+j-1;
                    e[ind].y=(i-1)*m+j;
                    e[ind].w=abs(mp[i][j]-mp[i][j-1]);
                    ind++;
                }
                if(i>1){
                    e[ind].x=(i-2)*m+j;
                    e[ind].y=(i-1)*m+j;
                    e[ind].w=abs(mp[i][j]-mp[i-1][j]);
                    ind++;
                }
            }
        }
        N=n*m;
        M=ind-1;
        printf("Case #%d:\n",cas);
        int ans=kruscal();
        printf("%d\n",ans);
    }
    return 0;
}
