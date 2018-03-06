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
#include <ctime>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
#include<climits>
using namespace std;
typedef long long ll;

#define maxn 505

vector<int> g[maxn];
int n,m;
bool cut[maxn];
bool flag;
int status[maxn];
int low[maxn];
int dfn[maxn];
int root;

void tarjan(int c,int from,int d){
    status[c]=1;
    low[c]=dfn[c]=d;
    int child=0;
    int sz=g[c].size();
    int v;
    for(int i=0;i<sz;i++){
        v=g[c][i];
        if(v!=from&&status[v]==1){
            low[c]=min(low[c],dfn[v]);
        }
        if(status[v]==0){
            tarjan(v,c,d+1);
            child++;
            low[c]=min(low[c],low[v]);
            if((c==root&&child>1)||(c!=root&&low[v]>=dfn[c])){
                cut[c]=true;
                flag=true;
            }
        }
    }
    status[c]=2;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m){
        if(n==0&&m==0)
            break;
        for(int i=0;i<n;i++){
            g[i].clear();
        }
        flag=false;
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
//            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(int i=0;i<n;i++){
            memset(cut,false,sizeof(cut));
            memset(status,0,sizeof(status));
            memset(dfn,0,sizeof(dfn));
            memset(low,0,sizeof(low));
            status[i]=2;
            if(i!=0)
                root=0;
            else
                root=1;
            tarjan(root,-1,1);
            for(int i=0;i<n;i++){
                if(status[i]==0){
                    flag=true;
                    break;
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        if(flag)
            cout<<"NO\n";
//            printf("NO\n");
        else
            cout<<"YES\n";
//            printf("YES\n");
    }
    return 0;
}
