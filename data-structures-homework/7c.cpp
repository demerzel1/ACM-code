#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int root=1;
int lch[1000],rch[1000],vis[1000],val[1000],cnt;
char s[1000];
vector<int> ans;

int Input(){
   memset(lch,0,sizeof lch);
   memset(rch,0,sizeof rch);
   memset(vis,0,sizeof vis);
   memset(val,0,sizeof val);
   cnt=root;
   while(1){
    if(scanf("%s",s)!=1) return false;
    if(!strcmp(s,"()")) break;
    int v;
    sscanf(&s[1],"%d",&v);
    char *st=strchr(s,',')+1;
    int u=root;
    for(int i=0;i<strlen(st)-1;i++){
        if(st[i]=='L'){
            if(!lch[u]) lch[u]=++cnt;
            u=lch[u];
        }
        if(st[i]=='R'){
            if(!rch[u]) rch[u]=++cnt;
            u=rch[u];
        }
    }
    vis[u]++;
    val[u]=v;
   }
   return true;
}
bool Bfs(){
    queue<int> Q;
    Q.push(root);
    ans.clear();
    while(!Q.empty()){
        int cur=Q.front();
        Q.pop();
        if(vis[cur]!=1)return false;
        ans.push_back(val[cur]);
        if(lch[cur]) Q.push(lch[cur]);
        if(rch[cur]) Q.push(rch[cur]);
    }
    return true;
}
int main(){
    while(Input()){
        if(!Bfs()){
            printf("not complete\n");
        }else{
            for(int i=0;i<ans.size()-1;i++){
                printf("%d ",ans[i]);
            }printf("%d\n",ans[ans.size()-1]);
        }
    }
    return 0;
}
