#include <bits/stdc++.h>
using namespace std;
 
const int maxn=505;
const int INF=0x3f3f3f3f;
int dis[maxn][maxn];
int col[maxn];
 
int n,m;
vector<int> g[maxn];
 
void floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
 
int from[maxn],tot;
bool use[maxn];
 
bool match(int x){
    for(const auto &i:g[x]){
        if(!use[i]){
            use[i]=true;
            if(from[i]==-1||match(from[i])){
                from[i]=x;
              //  from[x]=i;
                return true;
            }
        }
    }
    return false;
}
 
int hungary(){
    tot=0;
    memset(from,-1,sizeof(from));
    for(int i=1;i<=n;i++){
//        if(from[i]!=-1)
//            continue;
        memset(use,0,sizeof(use));
        if(match(i))
            tot++;
    }
    return tot;
}
 
bool dfs(int x,int c){
    col[x]=c;
    for(const auto &i:g[x]){
     //   cout<<"i= "<<i<<' '<<col[i]<<endl;
        if(col[i]!=-1){
            if(col[i]==c)
                return false;
        }else{
            if(!dfs(i,c^1))
                return false;
        }
    }
    return true;
}
 
bool paint(){
    memset(col,-1,sizeof(col));
    for(int i=1;i<=n;i++){
   //     cout<<i<<"  i\n";
        if(col[i]==-1){
            if(!dfs(i,0))
                return false;
        }
    }
    return true;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while((T--) != 0){
        int k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
            g[i].clear();
        int a,b,c;
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=n;i++)
            dis[i][i]=0;
        for(int i=1;i<=m;i++){
            cin>>a>>b>>c;
            dis[a][b]=c;
            dis[b][a]=c;
        }
        if(n==0){
            cout<<"0\n";
            continue;
        }
        floyd();
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(dis[i][j]<=k&&i!=j){
                    g[i].emplace_back(j);
                    g[j].emplace_back(i);
                }
            }
        }
        bool flag=true;
        int cnt=1;
       for(int i=1;i<=n;i++){
           if(dis[1][i]<INF)
               cnt++;
       }
        if(cnt<n)
            flag=false;
        if(flag) {
            if (!paint())
                flag = false;
          // cout<<hungary()<<endl;
            if (hungary()!= n)
                flag = false;
        }
        if(!flag){
            cout<<"Impossible\n";
            continue;
        }
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(col[i]==0)
                ans.emplace_back(i);
        }
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size()-1;i++)
            cout<<ans[i]<<' ';
        cout<<ans[ans.size()-1]<<"\n";
    }
    return 0;
}