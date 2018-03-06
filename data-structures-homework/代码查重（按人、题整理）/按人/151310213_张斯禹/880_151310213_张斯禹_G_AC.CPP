#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <functional>
#include <cmath>
#include <memory.h>
#include <cstdio>
#include <sstream>
#include <set>

using namespace std;

#define MAXN 105

int _map[MAXN<<1][MAXN<<1];
int match[MAXN<<1];
bool visited [MAXN<<1];
int object_num,aim_num;

bool dfs(int p)
{
    for(int i=object_num;i<object_num+aim_num;i++)
    {
        if(visited[i]==false&&_map[p][i])
        {
            visited[i]=true;
            if(match[i]==-1||dfs(match[i]))
            {
                match[i]=p;
                return true;
            }
        }
    }
    return false;
}

void hungarian()
{

    memset(match,-1,sizeof(match));
    int ans=0;
    for(int i=0;i<object_num;i++)
    {
        if(match[i]==-1)
        {

            memset(visited,0,sizeof(visited));
            if(dfs(i))
                ans++;
        }
    }
    cout<<ans<<endl;
}



int main()
{
    int times,num1,num2;
    while(scanf("%d%d",&object_num,&aim_num)!=EOF)
    {
        memset(_map,0,sizeof(_map));
        cin>>times;
        for(int i=0;i<times;i++)
        {
            scanf("%d%d",&num1,&num2);
            _map[num1-1][object_num+num2-1]=1;
            _map[object_num+num2-1][num1-1]=1;
        }
        hungarian();
    }
    return 0;
}

