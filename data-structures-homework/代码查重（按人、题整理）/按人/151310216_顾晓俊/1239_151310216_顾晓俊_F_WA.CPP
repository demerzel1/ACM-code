//6

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1005;

struct Edge
{
    int index;
    int u,v;
    int value;
};

bool cmp(const Edge a,const Edge b)
{
    return a.value < b.value;
}

int matrix[MAX][MAX];
bool connected[MAX][MAX];
vector<Edge> edge;
int n,m;
vector<int> ans;
vector<int> check;

void update(int u,int v)
{
    vector<int> con_u;
    vector<int> con_v;
    for(int i=0;i<n;i++){
        if(connected[u][i]){
            con_u.push_back(i);
        }
        if(connected[v][i]){
            con_v.push_back(i);
        }
    }
    for(int i=0;i<con_u.size();i++){
        for(int j=0;j<con_v.size();j++){
            connected[con_u[i]][con_v[j]] = true;
            connected[con_v[j]][con_u[i]] = true;
        }
    }
}

//bool all_connected()
//{
//    for(int i=0;i<n;i++){
//        if(!connected[0][i]){
//            return false;
//        }
//    }
//    return true;
//}

int main()
{
    while(cin>>n>>m){
        memset(matrix,0,sizeof(matrix));
        memset(connected,false,sizeof(connected));
        edge.resize(m);
        for(int i=0;i<m;i++){
            cin>>edge[i].u>>edge[i].v>>edge[i].value;
            edge[i].index = i+1;
        }
        sort(edge.begin(),edge.end(),cmp);

        ans.clear();
        int cnt=0;
        for(int i=0;i<m;i++){
            if(!connected[edge[i].u][edge[i].v]){
                ans.push_back(edge[i].index);
                cnt++;

                if(cnt==n-1){
                    break;
                }

                matrix[edge[i].u][edge[i].v] = edge[i].value;
                matrix[edge[i].v][edge[i].u] = edge[i].value;
                connected[edge[i].u][edge[i].v] = true;
                connected[edge[i].v][edge[i].u] = true;
                update(edge[i].u,edge[i].v);

                //if(all_connected()){
            }
        }
        sort(ans.begin(),ans.end());

        check.resize(n-1);
        for(int i=0;i<n-1;i++){
            cin>>check[i];
        }
        sort(check.begin(),check.end());
        bool correct = true;
        for(int i=0;i<n-1;i++){
            if(ans[i]!=check[i]){
                correct = false;
                break;
            }
        }
        if(correct){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}

