#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <cstring>
#include <queue>
#include <sstream>

using namespace std;


priority_queue<int,vector<int>,greater<int> >  q;


int main()
{
    int n,x,y,ans;
    while(cin>>n&&n!=0)
    {
        ans=0;
        while(!q.empty())
        {
            q.pop();
        }
        for(int i=0;i<n;i++)
        {
            cin>>x;
            q.push(x);
        }
        if(q.size()==1)
        {
            x=q.top();
            cout<<x<<endl;
        }
        else
        {
            while(q.size()>=2)
            {
                x=q.top();
                q.pop();
                y=q.top();
                q.pop();
                ans+=(x+y);
                q.push(x+y);
            }
            cout<<ans<<endl;
        }
    
    }
    return 0;
}

