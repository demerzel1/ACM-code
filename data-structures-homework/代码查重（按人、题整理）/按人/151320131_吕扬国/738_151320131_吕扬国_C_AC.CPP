#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> mm[1000005];
vector<int>::iterator it;
int m,n,q,x,y;
int main()
{
    while(cin>>m>>n)
    {
        for(int i=0;i<=m;i++)mm[i].clear();
        cin>>q;
        while(q--)
        {
            cin>>x>>y;
            for(it=mm[x].begin();it!=mm[x].end();it++)
            {
                if(*it==y) break;
            }
            if(it==mm[x].end())cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            mm[x].push_back(y);
        }
    }
    return 0;
}

