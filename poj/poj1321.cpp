#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <climits>
#include <ctime>
#include <complex>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 10

char mp[maxn][maxn];
bool vis[maxn];
int ans;
int n,k;

void dfs(int d,int num){
    if(num==k){
        ans++;
        return;
    }
    if(d>n)
        return;
    for(int i=0;i<n;i++){
        if(!vis[i]&&mp[d][i]=='#'){
            vis[i]=true;
            dfs(d+1,num+1);
            vis[i]=false;
        }
    }
    dfs(d+1,num);
    return;
}

int main(){
    while(cin>>n>>k){
        if(n==-1&&k==-1)
            break;
        for(int i=1;i<=n;i++)
            scanf("%s",mp[i]);
        ans=0;
        memset(vis,false,sizeof(vis));
        dfs(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}
