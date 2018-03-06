#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n,m;
char mp[10][10];
const int mod=772002;
int loc[1200];
int dx[]={-1,0,1,1,1,0,-1,-1};
int dy[]={1,1,1,0,-1,-1,-1,0};
ll dp[30][1200];
ll ans;

bool check(int x,int y){
    for(int k=0;k<8;k++){
        int tx=x+dx[k];
        int ty=y+dy[k];
        if(tx<0||tx>=n||ty<0||ty>=m)
            continue;
        if(mp[tx][ty]=='X'){
            return false;
        }
    }
    return true;
}

ll solve(){
    vector<pii> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='X'){
                v.emplace_back(i,j);
            }
        }
    }
    int num=v.size();
   // cout<<"num= "<<num<<endl;
    memset(loc,0,sizeof(loc));
    for(int t=0;t<(1<<num);t++){
        for(int i=0;i<num;i++){
            if(t&(1<<i)){
                mp[v[i].first][v[i].second]='!';
                loc[t]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mp[i][j]!='.')
                    continue;
                bool flag=true;
                for(int k=0;k<8;k++){
                    int tx=i+dx[k];
                    int ty=j+dy[k];
                    if(tx<0||tx>=n||ty<0||ty>=m)
                        continue;
                    if(mp[tx][ty]=='X'){
                        flag=false;
                        break;
                    }
                }
                if(flag)
                    loc[t]++;
            }
        }
        for(int i=0;i<num;i++){
            if(t&(1<<i)){
                mp[v[i].first][v[i].second]='X';
            }
        }
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<n*m;i++){
        for(int j=0;j<(1<<num);j++){
            if(dp[i][j]==0)
                continue;
            for(int k=0;k<num;k++){
                if(j>>k&1)
                    continue;
                dp[i+1][j^(1<<k)]=(dp[i+1][j^(1<<k)]+dp[i][j])%mod;
            }
            dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(loc[j]-i))%mod;
        }
    }
   // printf("dp=%lld\n",dp[n*m][(1<<num)-1]);
    return dp[n*m][(1<<num)-1];
}

void dfs(int x,int f){
    if(x==n*m){
    //    printf("111\n");
        if(f%2==0)
            ans+=solve();
        else
            ans-=solve();
        ans%=mod;
        return;
    }
    int tx=x/m,ty=x%m;
    if(mp[tx][ty]=='X'){
        dfs(x+1,f);
    }else{
        bool flag=true;
        for(int i=0;i<8;i++){
            int ttx=tx+dx[i],tty=ty+dy[i];
            if(ttx<0||ttx>=n||tty<0||tty>=m)
                continue;
            if(mp[ttx][tty]=='X'){
                flag=false;
                break;
            }
        }
        if(flag){
            mp[tx][ty]='X';
            dfs(x+1,f+1);
            mp[tx][ty]='.';
        }
        dfs(x+1,f);
    }
}

int main(){
    int cas=0;
    while(~scanf("%d%d",&n,&m)){
        bool flag=true;
        ans=0;
        for(int i=0;i<n;i++){
            scanf("%s",mp[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mp[i][j]=='X'){
                    if(!check(i,j)){
                        flag=false;
                        break;
                    }
                }
            }
            if(!flag)
                break;
        }
        if(!flag) {
            printf("Case #%d: ",++cas);
            printf("0\n");
            continue;
        }
        dfs(0,0);
        if(ans<0) ans+=mod;
        printf("Case #%d: ",++cas);
        printf("%lld\n",ans);
    }
    return 0;
}