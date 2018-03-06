#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>
#include <hash_map>

using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int index=-11;
        int cnt=0;
        int a[10]={0};
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<0)
            {
                index=max(index,a[i]);
                cnt++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]!=0) m*=a[i];
        }
        if(cnt%2!=0)
        {
            m/=index;
        }
        cout<<m<<endl;

    }

    return 0;
}

