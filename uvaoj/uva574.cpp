#include<bits/stdc++.h>
using namespace std;

int n,t;
int num[20];
bool vis[20];
int ans[20];
vector< vector<int> > lastans;
bool yes;
void dfs(int ind,int sum,int d){
    if(sum==t){
        bool f=true;
        int sz=lastans.size();
//        cout<<"sz="<<sz<<"\n";
        for(int j=0;j<sz;j++){
            if(d-1==lastans[j].size()){
//            cout<<"d="<<d<<"\n";
            for(int i=1;i<d;i++){
                if(ans[i]!=lastans[j][i-1]){
                    f=false;
                    break;
                }
            }
            if(f)
                return;
            }
            f=true;
        }
        cout<<ans[1];
        for(int i=2;i<d;i++){
            cout<<"+"<<ans[i];
        }
        cout<<"\n";
        yes=true;
        vector<int> v;
        for(int i=1;i<d;i++)
            v.push_back(ans[i]);
        lastans.push_back(v);
        return;
    }
    for(int i=ind;i<=n;i++){
        if(d==1&&i>1&&num[i]==num[i-1])
            continue;
        if(!vis[i]){
            vis[i]=true;
            ans[d]=num[i];
            dfs(i,sum+num[i],d+1);
            vis[i]=false;
        }
    }
}

int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
  //  int cnt=0;
    while(cin>>t>>n&&n){
      //  cnt++;
     //   cout<<"cnt="<<cnt<<"\n";
        lastans.clear();
        yes=false;
        memset(vis,false,sizeof(vis));
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++)
            cin>>num[i];
        cout<<"Sums of "<<t<<":\n";
        dfs(1,0,1);
        if(!yes)
            cout<<"NONE\n";
    }
    return 0;
}
