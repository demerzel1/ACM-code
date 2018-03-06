#pragma warning (disable:4996)
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
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const double EPS = 1e-9;
const double PI = 2 * asin(1);
const int INF = 0x7fffffff;
const LL LINF = 0x7fffffffffffffff;

int n,i,j,t,ans;
map<string,int> mp;
queue<int> q;
char str[90],first[90];
char STGD[1005][90];
int vis[1005],len[1005];
vector<int> G[1005];


bool IsNext(char *s1,char *s2){
    bool flag=false;
    int step1=0;
    int step2=0;
    while(s1[step1]!='\0'&&s2[step2]!='\0'){
        if(s1[step1]==s2[step2]){
            step1++;
            step2++;
        }
        if(s1[step1]!=s2[step2]&&!flag){
            step2++;
            flag=true;
        }
        if(s1[step1]!=s2[step2]&&flag){
            return false;
        }
    }
    return true;
}


int main(){
    scanf("%d%s",&n,first);
    for(i=0;i<n;i++){
        scanf("%s",STGD[i]);
        mp[STGD[i]]=i;
        len[i]=strlen(STGD[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)
                continue;
            if(len[i]+1==len[j]){
                if(IsNext(STGD[i],STGD[j])){
                    G[i].push_back(j);
                }
            }
        }
    }
    memset(vis,0,sizeof(vis));
    while (!q.empty())
        q.pop();
    ans=mp[first];
    q.push(ans);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(i=0;i<G[t].size();i++){
            if(vis[G[t][i]]==0) {
                vis[G[t][i]]=1;
                q.push(G[t][i]);
                if (len[G[t][i]] > len[ans])
                    ans=G[t][i];
            }

        }
    }
    printf("%s\n",STGD[ans]);
}
