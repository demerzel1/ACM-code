#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

class node{
    public:
        int u, v, weight, index;
    public:
        bool friend operator < (node n1, node n2)
        {
            return n1.weight > n2.weight;
        }
};

class MSTest{
    private:
        int numOfvertexes, numOfedges;
        priority_queue<node> p;
        vector<int> parents;
        vector<bool> vis;
        vector<int> index;
        string ans;

        int find(int r) { return r==parents[r] ? r:parents[r]=find(parents[r]); }
    public:
        void initial(int n, int m)
        {
            numOfvertexes=n, numOfedges=m;
            parents.clear(), vis.clear(), index.clear(), ans="";
            for(int i=0; i<=numOfvertexes; i++) parents.push_back(i);
            for(int i=0; i<=numOfedges; i++) vis.push_back(false);
            while(!p.empty()) p.pop();
        }
        void readcase()
        {
            node n;
            for(int i=1; i<=numOfedges; i++){
                scanf("%d%d%d", &n.u, &n.v, &n.weight);
                n.index=i;
                p.push(n);
            }
            for(int i=0; i<numOfvertexes-1; i++){
                index.push_back(0);
                scanf("%d", &index.at(i));
            }
        }
        void computing()
        {
            while(!p.empty()){
                int sn=find(p.top().u);
                int en=find(p.top().v);
                if(sn!=en){
                    parents[en]=sn;
                    vis[p.top().index]=true;
                }
                p.pop();
            }
            for(int i=0; i<numOfvertexes-1; i++){
                if(!vis[index.at(i)]){
                    ans="NO";
                    break;
                }
            }

        }
        void outresult()
        {
            if(ans=="NO") printf("NO\n");
            else printf("YES\n");
        }
};

int main()
{
    int n, m;
    MSTest mst;
    while(~scanf("%d%d", &n, &m)){
        mst.initial(n, m);
        mst.readcase();
        mst.computing();
        mst.outresult();
    }
    return 0;
}

