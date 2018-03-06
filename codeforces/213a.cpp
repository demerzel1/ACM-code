#include<bits/stdc++.h>
using namespace std;
#define maxn 205
#define INF 100000000
int n;
vector<int> mp[maxn];
int c[maxn];
int cnt[maxn];
int tempcnt[maxn];
int bfs(int k){
    queue<int> que[4];
    for(int i=1;i<=n;i++)
        if(cnt[i]==0)
            que[c[i]].push(i);
    memset(tempcnt,0,sizeof(tempcnt));
    for(int i=1;i<=n;i++)
        tempcnt[i]=cnt[i];
    int tans=-1;
    while(!que[1].empty()||!que[2].empty()||!que[3].empty()){
        tans++;
        while(!que[k].empty()){
            int f=que[k].front();
            que[k].pop();
            tans++;
            int n2=mp[f].size();
            for(int i=0;i<n2;i++){
                int v=mp[f][i];
                tempcnt[v]--;
                if(tempcnt[v]==0){
                    que[c[v]].push(v);
                }
            }
        }
        if(k==1||k==2) k++;
        else if(k==3) k=1;
    }
    if(tans!=-1)
        return tans;
    else
        return 0;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    int n1;
    for(int i=1;i<=n;i++){
        scanf("%d",&n1);
        for(int j=0;j<n1;j++){
            int a;
            scanf("%d",&a);
            mp[a].push_back(i);
            cnt[i]++;
        }
    }
    int ans=INF;
    for(int i=1;i<=3;i++){
        int tans=bfs(i);
        ans=min(ans,tans);
    }
    printf("%d",ans);
    return 0;
}
