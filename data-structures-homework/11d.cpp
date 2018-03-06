#include<bits/stdc++.h>
using namespace std;
int n,m,par[30010],x,y,u,v;
string s;
char ch;
int find(int x){
    if(par[x]==x)return x;
    else return par[x]=find(par[x]);
}
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        cin>>n;
        getchar();
        for(int i=1;i<=n;i++){
            par[i]=i;
        }
        int sc=0,uc=0;
        while(getline(cin,s)){
            if(s.size()==0) break;
            stringstream ss;
            ss<<s;
            ss>>ch>>x>>y;
            u=find(x);
            v=find(y);
            if(ch=='q'){
                if(u!=v) uc++;
                else sc++;
            }
            else{
                if(u!=v) par[v]=u;
            }
        }
        printf("%d,%d\n",sc,uc);
        if(tc){
            cout<<endl;
        }
    }
    return 0;
}
