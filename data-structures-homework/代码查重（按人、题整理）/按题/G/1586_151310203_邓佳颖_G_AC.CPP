//Code here
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
const int MAXN=200;
vector<int> mat[MAXN];
int use[MAXN];
int boy[MAXN];

int can(int b){
    for(int i=0;i<mat[b].size();i++){
        int g=mat[b][i];
        if(use[g]==0){
            use[g]=1;
            if(boy[g]==-1||can(boy[g])){
                boy[g]=b;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<MAXN;i++){
            mat[i].clear();
        }
        memset(boy,0xff,sizeof(boy));
        int q;
        scanf("%d",&q);
        //vector<int> in;
        for(int i=0;i<q;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            //in.push_back(a);
            mat[a].push_back(b);
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            memset(use,0,sizeof(use));
            if(can(i)) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}

