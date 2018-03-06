#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <map>
#include <list>
#include <cstring>
#include <cmath>
using namespace std;
int n,m;
int main()
{
    vector<int> b;
    int x;
    while(scanf("%d%d",&n,&m))
    {
        b.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x>0)
            {
                m=m*x;
            }
            else
            {
                b.push_back(x);
            }
        }
        if(b.size()%2==0)
        {
            for(int i=0;i<b.size();i++)
            {
                m=m*b[i];
            }
        }
        else
        {
            sort(b.begin(),b.end());
            for(int i=0;i<b.size()-1;i++)
            {
             m=m*b[i];
            }
        }
        printf("%d\n",m);
    }
    return 0;
}

