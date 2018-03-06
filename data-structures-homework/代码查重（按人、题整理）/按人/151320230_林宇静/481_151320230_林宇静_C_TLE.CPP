#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
    map<int,vector<int>> p;
    int n,m,q;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++)
           p[i].clear();
        scanf("%d",&q);
        int x,y;
        for(int i=0;i<q;i++){
            scanf("%d%d",&x,&y);
            int flag=0;
            for(int j=0;j<p[x].size();j++){
                if(p[x][j]==y){
                    flag=1;
                    break;
                }
            }
            if(flag)
                cout<<"NO"<<endl;
            else{
                cout<<"YES"<<endl;
                p[x].push_back(y);
            }
        }
    }
    return 0;
}

