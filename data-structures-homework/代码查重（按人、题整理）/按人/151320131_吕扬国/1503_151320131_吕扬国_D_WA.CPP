#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> mm,nn;
vector<int>::iterator it;
int m,n,q;
long long t;
int main()
{
    while(cin>>m>>n)
    {
        mm.clear();
        nn.clear();
        t=0;
        for(int i=0;i<n;i++)
        {
            cin>>q;
            mm.push_back(q);
        }
        sort(mm.begin(),mm.end());
        for(int i=0;i<m;i++)
        {
            cin>>q;
            nn.push_back(q);
        }
        sort(nn.begin(),nn.end());
        if(n>m)
        {
            for(int i=0;i<nn.size();i++)
            {
            it=lower_bound(mm.begin(),mm.end(),nn[i]);
            if(it==mm.end())
            {
                it--;
                t+=fabs(*it-nn[i]);
                mm.erase(it);
            }
            else {
            t+=fabs(*it-nn[i]);
            mm.erase(it);
            }
            }
        }
        else
        {
            {
            for(int i=0;i<mm.size();i++)
            {
            it=lower_bound(nn.begin(),nn.end(),mm[i]);
            if(it==nn.end())
            {
                it--;
                t+=fabs(*it-mm[i]);
                nn.erase(it);
            }
            else {
            t+=fabs(*it-mm[i]);
            nn.erase(it);
            }
            }
        }
        }
        cout<<t<<endl;
    }
    return 0;
}

