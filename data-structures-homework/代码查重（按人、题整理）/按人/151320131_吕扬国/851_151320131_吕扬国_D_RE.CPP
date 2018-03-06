#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> mm;
vector<int>::iterator it;
int m,n,q,t;
int main()
{
    while(cin>>m>>n)
    {
        mm.clear();
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
            it=lower_bound(mm.begin(),mm.end(),q);
            if(it==mm.end())
            {
                it--;
                t+=fabs(*it-q);
                mm.erase(it);
            }
            else {
            t+=fabs(*it-q);
            mm.erase(it);
            }
        }
        cout<<t<<endl;
    }
    return 0;
}

