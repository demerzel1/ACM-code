#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int m,n;
    int a[20];
    while(cin>>m>>n)
    {
        for(int i=0;i<m;i++)cin>>a[i];
        sort(a,a+m);
        for(int i=0;i<m;i++)
        {
            if(i<m-1&&a[i]<0&&a[i+1]<0)
            {n=n*a[i]*a[i+1];i++;}
            else if(a[i]>0) n=n*a[i];
        }
        cout<<n<<endl;
    }
    return 0;
}

