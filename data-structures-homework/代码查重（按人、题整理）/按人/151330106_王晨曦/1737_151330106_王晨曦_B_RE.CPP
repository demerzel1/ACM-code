#include <iostream>
#include <vector>
#include <map>

using namespace std;

class doc
{
public:

    long long int cost;
    int locate;
    doc(long long int cost,int locate):cost(cost),locate(locate)
    {

    }
};

vector<doc>maps[10005];
int emergency[10005];

void initial(int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        maps[i].clear();
    }
}

long long int DFS(int location,long long int cost,long long int money,long long int emergencyvalue)
{
    long long int mid;
    if(money-cost<=0)
        return emergencyvalue;
    else
        money-=cost;
        
    if(maps[location].empty())
        return emergencyvalue;

    for(int i=0;i<maps[location].size();i++)
    {
        mid=DFS(maps[location][i].locate, maps[location][i].cost, money ,emergencyvalue+emergency[maps[location][i].locate]);
        if(mid>emergencyvalue)
        {
            emergencyvalue=mid;
        }
    }
    return emergencyvalue;


}



int main()
{
    int n,m;
    long long int l;
    while(cin>>n>>m>>l)
    {
        initial(n,m);
        int u,v;
        long long int c;
        while(m--)
        {
            cin>>u>>v>>c;
            maps[u].push_back(doc(v,c));
        }
        long long int value;
        for(int i=1;i<=n;i++)
        {
            cin>>value;
            emergency[i]=value;
        }
        long long int sum=DFS(1,0,l,0);
        if(sum==0)
            sum+=emergency[1];
        cout<<sum<<endl;
    }
    return 0;
}

