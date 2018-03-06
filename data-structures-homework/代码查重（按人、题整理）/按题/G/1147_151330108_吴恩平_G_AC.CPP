#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define maxn 10005
using namespace std;

vector<int> edge[maxn];
bool check[maxn];
int Jessicamatch[maxn];

class HappyNewYear{
    private:
        int numOfJetoys, numOfLilytoys, numOfexchange, ans;

        bool dfs(int u)
        {
            for(int i=0; i<(int)edge[u].size(); i++){
                int v=edge[u].at(i);
                if(!check[v]){
                    check[v]=true;
                    if(Jessicamatch[v]==-1 || dfs(Jessicamatch[v]) ){
                        Jessicamatch[v]=u;
                        return true;
                    }
                }
            }
            return false;
        }
        void hungary()
        {
            for(int i=1; i<=numOfJetoys; i++){
                if(dfs(i)) ans++;
                memset(check, false, sizeof(check));
            }
        }
    public:
        void initial()
        {
            ans=0;
            for(int i=0; i<maxn; i++) edge[i].clear();
            memset(check, false, sizeof(check));
            memset(Jessicamatch, -1, sizeof(Jessicamatch));
        }
        void readcase(int n, int m)
        {
            numOfJetoys=n, numOfLilytoys=m;
            scanf("%d", &numOfexchange);
            int u, v;
            for(int i=1; i<=numOfexchange; i++){
                scanf("%d%d", &u, &v);
                edge[u].push_back(v);
            }
        }
        void computing()
        {
            hungary();
        }
        void outresult()
        {
            printf("%d\n", ans);
        }
};

int main()
{
    int n, m;
    HappyNewYear hny;
    while(~scanf("%d%d", &n, &m)){
        hny.initial();
        hny.readcase(n, m);
        hny.computing();
        hny.outresult();
    }
    return 0;
}

