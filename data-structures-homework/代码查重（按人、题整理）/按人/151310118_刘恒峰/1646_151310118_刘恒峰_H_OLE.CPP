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


string a,b;
int Next[1000005];
int n,m;
int ans[1000005];
int cnt;
void getnext()
{
    memset(Next,0,sizeof(Next));
    for (int i=1,j=0;i<m;i++)
    {
        while (j>0 && b[i]!=b[j])
        {
            j=Next[j-1];
        }
        if (b[i]==b[j])
        {
            j++;
        }
        Next[i]=j;
    }
}
void kmp()
{
    memset(ans,0,sizeof(ans));
    cnt=0;
    for (int i=0,j=0;i<n;i++)
    {
        while (j>0 && a[i]!=b[j])
        {
            j=Next[j-1];
        }
        if (a[i]==b[j])
        {
            j++;
        }
        if (j==m)
        {
            ans[cnt]=i-m+2;
            cnt++;
            
        }
    }
}
int main()
{
    while(cin>>n)
    {
        getchar();
        getline(cin,a);
        cin>>m;
        getchar();
        getline(cin,b);
        getnext();
        kmp();
        cout<<cnt<<endl;
        for (int i=0;i<cnt;i++)
        {
            cout<<ans[i];
            if (i!=cnt-1)
            {
                cout<<' ';
            }
            else 
            {
                cout<<endl;
            }
        }
        if (cnt==0)
        {
            cout<<endl;
        }
    }
    return 0;
}

