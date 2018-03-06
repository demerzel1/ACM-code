//7

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

const int MAX = 105;

bool matrix[MAX][MAX];
int link[MAX];
bool visited[MAX];
int n,m;

bool can(int t)
{
    for(int i=0;i<m;i++){
        if(!visited[i]&&matrix[t][i]){
            visited[i] = true;
            if(link[i]==-1||can(link[i])){
                link[i] = t;
                return true;
            }
        }
    }
    return false;
}

int MaxMatch()
{
    int num=0;
    memset(link,-1,sizeof(link));
    for(int i=0;i<n;i++){
        memset(visited,false,sizeof(visited));
        if(can(i)){
            num++;
        }
    }
    return num;
}

int main()
{
    int k;
    while(cin>>n>>m>>k){
        memset(matrix,false,sizeof(matrix));
        for(int i=0;i<k;i++){
            int a,b;
            cin>>a>>b;
            matrix[a-1][b-1] = true;
        }

        cout<<MaxMatch()<<endl;
    }
    return 0;
}

