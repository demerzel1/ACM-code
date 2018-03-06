#include<bits/stdc++.h>
using namespace std;
#define maxn 2017

int n,k;
map<int,int> mp;
int a[maxn];
int ans[maxn];
int ind;

void bfs() {
    queue<int> q;
    for(int i=0; i<ind; i++) {
        ans[a[i]+1000]=1;
        q.push(a[i]);
    }
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int i=0; i<ind; i++) {
            if(u+a[i]<=1000&&u+a[i]>=-1000) {
                if(ans[u+a[i]+1000]==0) {
                    ans[u+a[i]+1000]=ans[u+1000]+1;
                    q.push(u+a[i]);
                }
            }
        }
    }
    if(ans[1000]==0)
        printf("-1");
    else
        printf("%d",ans[1000]);
}

int main() {
    scanf("%d%d",&n,&k);
    for(int i=0; i<k; i++) {
        int x;
        scanf("%d",&x);
        x-=n;
        if(mp[x]==0) {
            mp[x]=1;
            a[ind++]=x;
        }
    }
    bfs();
    return 0;
}
