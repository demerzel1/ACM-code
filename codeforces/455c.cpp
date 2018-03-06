#include<bits/stdc++.h>
using namespace std;
#define maxn 300005

int n,m,q;
vector<int> G[maxn];
int pre[maxn];
int ans;
int far;
int tans[maxn];

void dfs(int c,int p,int r,int d){
    pre[c]=r;
    if(d>ans){
        ans=d;
        far=c;
    }
    int sz=G[c].size();
    for(int i=0;i<sz;i++){
        if(G[c][i]==p)
            continue;
        dfs(G[c][i],c,r,d+1);
    }
    return;
}

int Find(int x) {
    int r=x;
    while(pre[r]!=r)
        r=pre[r];
    int i=x,j;
    while(i!=r) {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y) {
    int fx=Find(x),fy=Find(y);
    if(fx!=fy){
        pre[fx]=fy;
//        cout<<fx<<" "<<fy<<" "<<tans[fx]<<" "<<tans[fy]<<"\n";
        if(tans[fx]>tans[fy])
            swap(tans[fx],tans[fy]);
        tans[fy]=max(max(tans[fx],tans[fy]),(tans[fx]+1)/2+(tans[fy]+1)/2+1);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>q;
    int a,b;
    for(int i=0;i<=n;i++){
        pre[i]=i;
        G[i].clear();
    }

    for(int i=0; i<m; i++) {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(pre[i]==i){
            far=i;
            ans=-1000000;
            dfs(i,0,i,0);
            ans=-1000000;
//            cout<<"i="<<i<<" far="<<far<<"\n";
            dfs(far,0,i,0);
            tans[i]=ans;
//            cout<<"ans="<<ans<<"\n";
        }
    }
    int op;
    for(int i=0;i<q;i++){
        cin>>op;
        if(op==1){
            cin>>a;
            cout<<tans[Find(a)]<<"\n";
        }else{
            cin>>a>>b;
            join(a,b);
        }
    }
    return 0;
}
