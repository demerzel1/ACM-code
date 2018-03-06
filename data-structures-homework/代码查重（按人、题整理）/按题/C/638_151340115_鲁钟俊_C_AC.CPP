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


map<string,int>  mp;


int main()
{
    int t,n,m,q,x,y;
    while(cin>>n>>m)
    {
        mp.clear();
        cin>>q;
        for(int i=0;i<q;i++)
        {
            string s1,s2;
            cin>>x>>y;
            while(x>0)
            {
                t=x%10;
                x/=10;
                char c=t+'0';
                s1+=c;
            }
            s1+="A";
            while(y>0)
            {
                t=y%10;
                y/=10;
                char c=t+'0';
                s2+=c;
            }
            s2+="B";
            s1+=s2;
            if(mp.find(s1)!=mp.end())
            {
                cout<<"NO"<<endl;
            }
            else
            {
                mp[s1]=1;
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}

