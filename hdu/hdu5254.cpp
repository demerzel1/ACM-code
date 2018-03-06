#include<bits/stdc++.h>
using namespace std;
#define maxn 505
bool mp[maxn][maxn];
using pii=pair<int,int>;
queue<pair<int,int> >  q;

int dx[]={-1,-1,1,1};
int dy[]={-1,1,-1,1};



int main(){
    int T;
    scanf("%d",&T);
    int cas=0;
    while(T--){
        cas++;
        int n,m;
        scanf("%d%d",&n,&m);
        memset(mp,false,sizeof(mp));
        int g;
        scanf("%d",&g);
        int a,b;
        for(int i=0;i<g;i++){
            scanf("%d%d",&a,&b);
            mp[a][b]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j])
                    q.push(make_pair(i,j));
            }
        }
        while(!q.empty()){
            pii p=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int tx=p.first+dx[k];
                int ty=p.second+dy[k];
                if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&mp[tx][ty]){
                    if(k==0){
                        int ttx=tx;
                        int tty=ty+1;
                        if(!mp[ttx][tty]){
                            mp[ttx][tty]=true;
                            q.push(make_pair(ttx,tty));
                      //      cout<<111<<"\n";
                        }
                        ttx=tx+1;
                        tty=ty;
                        if(!mp[ttx][tty]){
                            mp[ttx][tty]=true;
                            q.push(make_pair(ttx,tty));
                       //     cout<<111<<"\n";
                        }
                    }
                    if(k==1){
                        int ttx=tx;
                        int tty=ty-1;
                        if(!mp[ttx][tty]){
                            mp[ttx][tty]=true;
                            q.push(make_pair(ttx,tty));
                       //     cout<<222<<"\n";
                        }
                        ttx=tx+1;
                        tty=ty;
                        if(!mp[ttx][tty]){
                            mp[ttx][tty]=true;
                            q.push(make_pair(ttx,tty));
                       //     cout<<222<<"\n";
                        }
                    }
                    if(k==2){
                        int ttx=tx;
                        int tty=ty+1;
                        if(!mp[ttx][tty]){
                            mp[ttx][tty]=true;
                            q.push(make_pair(ttx,tty));
                      //      cout<<333<<"\n";
                        }
                        ttx=tx-1;
                        tty=ty;
                        if(!mp[ttx][tty]){
                            mp[ttx][tty]=true;
                            q.push(make_pair(ttx,tty));
                       //     cout<<333<<"\n";
                        }
                    }
                    if(k==3){
                        int ttx=tx;
                        int tty=ty-1;
                        if(!mp[ttx][tty]){
                        //    printf("tx=%d ty=%d ttx=%d tty=%d\n",tx,ty,ttx,tty);
                            mp[ttx][tty]=true;
                            q.push(make_pair(ttx,tty));
                        //    cout<<444<<"\n";
                        }
                        ttx=tx-1;
                        tty=ty;
                        if(!mp[ttx][tty]){
                       //     printf("tx=%d ty=%d ttx=%d tty=%d\n",tx,ty,ttx,tty);
                            mp[ttx][tty]=true;
                            q.push(make_pair(ttx,tty));
                       //     cout<<444<<"\n";
                        }
                    }
                }
            }
        }
        int ans=0;
       // printf("aaa\n");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j]){
            //        printf("%d %d\n",i,j);
                    ans++;
                }
            }
        }
        printf("Case #%d:\n%d\n",cas,ans);
    }
    return 0;
}
