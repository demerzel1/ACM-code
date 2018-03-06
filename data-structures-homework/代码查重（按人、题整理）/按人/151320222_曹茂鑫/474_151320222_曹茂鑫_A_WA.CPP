#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int i,a[15],t=-11,m,n,flag;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        flag=1;
        for(i=1;i<=m;i++)
        {
        cin>>a[i];
        if(a[i]<0)
            {
            flag=-flag;
            if(a[i]>t)t=a[i];
            }
        }
        for(i=1;i<=m;i++)
        {
            n=n*a[i];
        }
    if(flag==-1)n=n/t;
    cout<<n<<endl;
    }
    return 0;
}

