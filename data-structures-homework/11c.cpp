#include<bits/stdc++.h>
using namespace std;
int par[50005];
int find(int x){
    if(par[x]==x) return x;
    else return par[x]=find(par[x]);
}
int main(){
    int n,m,tc=1;
    while(cin>>n>>m){
        if(!n&&!m) break;
        for(int i=1;i<=n;i++)
            par[i]=i;
        int r=n;
        for(int j=0;j<m;j++){
            int a,b;
            cin>>a>>b;
            int u=find(a);
            int v=find(b);
            if(u!=v){
                par[v]=u;
                r--;
            }
        }
        cout<<"Case "<<tc<<": "<<r<<endl;
        tc++;
    }
    return 0;
}
