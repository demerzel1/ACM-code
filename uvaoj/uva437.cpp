#include<bits/stdc++.h>
using namespace std;
#define maxn 105

int n;
typedef struct node{
    int a;
    int b;
    int c;
    node(int aa=0,int bb=0,int cc=0){
        a=aa;
        b=bb;
        c=cc;
    }
}node;

vector<node> v;
vector<int> g[maxn];

bool judge(node n1,node n2){
    if((n1.a<n2.a&&n1.b<n2.b)||(n1.a<n2.b&&n1.b<n2.a)){
//        cout<<n1.a<<" "<<n1.b<<" "<<n2.a<<" "<<n2.b<<"\n";
        return true;
    }

    return false;
}

int ans=0;
int d[maxn];
int dfs(int x){
    if(d[x]!=-1)
        return d[x];
    d[x]=v[x].c;
    for(int i=0;i<g[x].size();i++)
        d[x]=max(d[x],dfs(g[x][i])+v[x].c);
    return d[x];
}

int main(){
    int cas=0;
    while(cin>>n&&n){
        cas++;
        ans=0;
        v.clear();
        for(int i=0;i<maxn;i++)
            g[i].clear();
        memset(d,-1,sizeof(d));
        int a,b,c;
        for(int i=0;i<n;i++){
            cin>>a>>b>>c;
            v.push_back(node(a,b,c));
            v.push_back(node(a,c,b));
            v.push_back(node(c,b,a));
        }
        for(int i=0;i<3*n;i++){
            for(int j=0;j<3*n;j++){
                if(judge(v[j],v[i])){
//                    cout<<"tu="<<i<<" "<<j<<"\n";
                    g[i].push_back(j);
                }
            }
        }
        for(int i=0;i<3*n;i++)
            ans=max(ans,dfs(i));
        cout<<"Case "<<cas<<": maximum height = "<<ans<<"\n";
    }
    return 0;
}
