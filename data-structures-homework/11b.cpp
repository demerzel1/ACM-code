#include<bits/stdc++.h>
using namespace std;
int rep[27];

int find(int x){
    if(rep[x]==x) return x;
    else return rep[x]=find(rep[x]);
}
int main(){
    int tc,t=0;
    cin>>tc;
    getchar();
    while(tc--){
        char s;
        cin>>s;
        getchar();
        for(int i=0;i<=(s-'A');i++)
            rep[i]=i;
        int res=1+s-'A';
        string fnd;
        while(getline(cin,fnd)){
            if(fnd.size()==0) break;
            int u=find(fnd[0]-'A');
            int v=find(fnd[1]-'A');
            if(u!=v){rep[v]=u;res--;}
        }
        if(tc)
            cout<<res<<endl<<endl;
        else
            cout<<res<<endl;
    }
    return 0;
}
