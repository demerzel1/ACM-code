#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <queue>
#include <list>
#include <cstring>
#include <cmath>


using namespace std;

vector<int> chess[1000005];
vector<int> a;
int main()
{
    int n,m;
    while (cin>>n>>m)
    {
        for (int i=0;i<1000005;i++)
        {
            chess[i].clear();
        }
        int t,xi,yi;
        cin>>t;
        for (int i=0;i<t;i++)
        {
            scanf("%d%d",&xi,&yi);
            bool flag=true;
            auto it=chess[xi].begin();
            for (;it!=chess[xi].end();it++)
            {
                if (*it==yi)
                {
                    flag=false;
                    cout<<"NO"<<endl;
                }
            }
            if (flag==true)
            {
                chess[xi].push_back(yi);
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}

