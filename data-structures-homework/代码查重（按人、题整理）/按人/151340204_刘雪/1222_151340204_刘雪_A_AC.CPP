#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

class InterestingGame
{
private:
    queue<int>node;
    vector<int>save;
    int start;
    int cnt;
public:
    void initial(int);
    void readCase(int);
    void computing();
    void outResult();
};
void InterestingGame::initial(int m)
{
    start=m;
    cnt=0;
    save.clear();
    while(!node.empty())
        node.pop();
}
void InterestingGame::readCase(int n)
{
    int x;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        if(x<0)
        {
            cnt++;
            x=0-x;
            save.push_back(x);
        }
        else if(x>0)
            node.push(x);
    }
    if(cnt)
        sort(save.begin(),save.end());
}
void InterestingGame::computing()
{
    if(cnt)
    {
        for(int i=save.size()-1; i>0; i--)
        {
            node.push(save[i]);
        }
        if(!(cnt%2))
            node.push(save[0]);
    }
    while(!node.empty())
    {
        int t=node.front();
        //printf("%d\n",t);
        node.pop();
        start*=t;
    }
}
void InterestingGame::outResult()
{
    printf("%d\n",start);
}
int main()
{
    InterestingGame ig;
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ig.initial(m);
        ig.readCase(n);
        ig.computing();
        ig.outResult();
    }
    return 0;
}

