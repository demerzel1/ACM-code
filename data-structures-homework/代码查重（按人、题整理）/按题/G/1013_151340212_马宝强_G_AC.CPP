#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <vector>
#define Max_Value 1000000
using namespace std;
int Jess[110],used[110],rule[110][110];
int N,M,K;
int temp1,temp2;
bool Find(int x)
{
    for(int i=1;i<=M;i++)
    {
        if(rule[x][i]==1&&used[i]==0)
        {
            used[i]=1;
            if(Jess[i]==0||Find(Jess[i]))
            {
                Jess[i]=x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin.sync_with_stdio(false);
    while(cin>>N>>M>>K)
    {
        int sum=0;
        memset(rule,0,sizeof(rule));
        memset(Jess,0,sizeof(Jess));
        for(int i=1;i<=K;i++)
        {
            cin>>temp1>>temp2;
            rule[temp1][temp2]=1;
        }
        for(int i=1;i<=N;i++)
        {
            memset(used,0,sizeof(used));
            if(Find(i))
                sum++;
        }
        cout<<sum<<endl;
    }
}

