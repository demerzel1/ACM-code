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

    int x;
    int n,m;
    vector<int> b;
    while(~scanf("%d%d",&n,&m)&&n!=0&&m!=0)
    {
        b.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x!=0)
            m*=x;
            if(x<0)
            {
                b.push_back(x);
            }
        }
        if(m<0)
        {

            sort(b.begin(),b.end());
            m=m/b[b.size()-1];
        }
        printf("%d\n",m);
    }
    return 0;
}

