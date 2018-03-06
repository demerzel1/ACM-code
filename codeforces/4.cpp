#include<bits/stdc++.h>
using namespace std;
#define maxn 22
int num[maxn];
bool vis[maxn];
int n;
int l;
bool cmp(int a,int b){
    return a>b;
}

bool dfs(int ind,int s,int cnt){
    int t=s;
    if(cnt==3) return true;
    for(int i=ind;i<n;i++){
        if(vis[i])
            continue;
        vis[i]=true;
        if(num[i]==s){
            if(dfs(0,l,cnt+1))
                return true;
            }else if(num[i]<s){
            if(dfs(i+1,s-num[i],cnt))
                return true;
            }
        vis[i]=false;
    }
    return false;
}

int main(){
    int t;
    int sum=0;
    scanf("%d",&t);
    while(t--){
        sum=0;
        memset(vis,false,sizeof(vis));
        memset(num,0,sizeof(num));
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&num[i]);
            sum+=num[i];
        }
        l=sum/4;
        sort(num,num+n,cmp);
        if(l*4!=sum){
            printf("no\n");
            continue;
        }
       // printf("l=%d\n",l);
    //    cout<<dfs(0,num[0],l,0)<<"\n";
        if(dfs(0,l,0)){
            printf("yes\n");
        }else
            printf("no\n");
    }
    return 0;
}
