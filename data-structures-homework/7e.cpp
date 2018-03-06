#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;

typedef long long LL;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ld> vd;

#define For(i,n) for(int i=0;i<(n);++i)
#define pb push_back
#define fi first
#define se second

const int maxn=5000;
string s1,s2;
map<string,int> mp;
int fa[maxn],tot,f[maxn],level[maxn];
bool vis[maxn];

void dfs(int p){
    vis[p]=true;
    if(!vis[fa[p]]) dfs(fa[p]);
    level[p]=level[fa[p]]+1;
}
void pp(int p){
    for(int i=2;i<=p;i++) cout<<"great ";
    if(p>=1) cout<<"grand ";
    cout<<"parent"<<endl;
}
void pc(int p){
    for(int i=2;i<=p;i++) cout<<"great ";
    if(p>=1) cout<<"grand ";
    cout<<"child"<<endl;
}
int find_(int p){
    return (f[p]==p)?f[p]=p:f[p]=find_(f[p]);
}
int main(){
    mp.clear();
    tot=0;
    for(int i=0;i<maxn;i++) f[i]=fa[i]=i;
    while(cin>>s1>>s2){
        if(s1=="no.child") break;
        if(mp.find(s1)==mp.end()){mp[s1]=tot++;}
        if(mp.find(s2)==mp.end()){mp[s2]=tot++;}
        fa[mp[s1]]=mp[s2];
        f[mp[s1]]=mp[s2];
    }
    memset(vis,false,sizeof(vis));
    for(int i=0;i<tot;i++)
    if(fa[i]==i){
        level[i]=0;
        vis[i]=true;
    }
    for(int i=0;i<tot;i++)  if(!vis[i]) dfs(i);
    int tp,tm;
    while(cin>>s1>>s2){
        if(mp.find(s1)==mp.end()||mp.find(s2)==mp.end())
            cout<<"no relation"<<endl;
        else if(find_(mp[s1])!=find_(mp[s2]))
            cout<<"no relation"<<endl;
        else{
            tp=mp[s1];
            tm=mp[s2];
            int i,j,up;
            i=-1;
            while(level[tp]>level[tm]){
                tp=fa[tp];
                i++;
            }
            j=-1;
            while(level[tm]>level[tp]){
                tm=fa[tm];
                j++;
            }
            if(tp==tm){
                if(i==-1) pp(j);
                else if(j==-1) pc(i);
                else cout<<"no relation"<<endl;
                continue;
            }
            up=-1;
            while(tp!=tm){
                tp=fa[tp];
                tm=fa[tm];
                up++;
            }
            if(up==0&&i==-1&&j==-1) cout<<"sibling"<<endl;
            else{
                cout<<up<<" cousin";
                if(max(i,j)+1>0) cout<<" removed "<<max(i,j)+1<<endl;
                else cout<<endl;
            }
        }
    }
    return 0;
}
