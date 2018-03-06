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
        int numOfvertexes, numOfedges, visnum, visnum2, sum, sum2;
        priority_queue<node> p;
        vector<int> parents;
        vector<node> giveedge;
        vector<int> index;
        string ans;

        int find(int r) { return r==parents[r] ? r:parents[r]=find(parents[r]); }
    public:
        void initial(int n, int m)
        {
            numOfvertexes=n, numOfedges=m, visnum=visnum2=0, sum=sum2=0;
            parents.clear(), giveedge.clear(), index.clear(), ans="";
            for(int i=0; i<=numOfvertexes; i++) parents.push_back(i);
            while(!p.empty()) p.pop();
        }
        void readcase()
        {
            node n;
            giveedge.push_back(n);
            for(int i=1; i<=numOfedges; i++){
                scanf("%d%d%d", &n.u, &n.v, &n.weight);
                n.index=i;
                p.push(n), giveedge.push_back(n);
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
                    sum+=p.top().weight;
                    visnum++;
                }
                p.pop();
            }
            parents.clear();
           for(int i=0; i<=numOfvertexes; i++) parents.push_back(i);
            /*while(!p.empty()) p.pop();
            for(int i=1; i<=numOfedges; i++)
                p.push(giveedge.at(i));*/
            if(visnum==numOfvertexes-1){
                for(int i=0; i<(int)index.size(); i++){
                    int sn=find( giveedge.at(index.at(i)).u );
                    int en=find( giveedge.at(index.at(i)).v );
                    if(sn!=en){
                        parents[en]=sn;
                        sum2+=giveedge.at(index.at(i)).weight;
                        visnum2++;
                    }
                }
                /*while(!p.empty()){
                    int sn=find(p.top().u);
                    int en=find(p.top().v);
                    if(sn!=en){
                        parents[en]=sn;
                        sum2+=p.top().weight;
                    }
                    p.pop();
                }*/
            }else ans="NO";
        }
        void outresult()
        {
            //cout << sum << " " << sum2 << endl;
            //cout << visnum2 << " " << visnum << endl;
            if(ans=="NO") printf("NO\n");
            else {
                if(sum2==sum && visnum2==visnum ) printf("YES\n");
                else printf("NO\n");
            }
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
/*
4 5
1 2 2
2 3 2
3 4 3
1 4 1
1 3 1
1 2 3
4 5
1 2 2
2 3 2
3 4 3
1 4 1
1 3 1
2 4 5

*/

