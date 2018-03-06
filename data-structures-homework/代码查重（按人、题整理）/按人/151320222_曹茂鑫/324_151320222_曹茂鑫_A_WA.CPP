#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    long long i,a[15],sum,t;
    int m,n;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        t=n;
        a[0]=n;
        for(i=1;i<=m;i++)cin>>a[i];
        for(i=0,sum=1;i<=m;i++)
        {
            sum=sum*a[i];
            if(sum==0)
            {
            sum=t;
            break;
            }
            else if(sum>0)
            {
            t=sum;
            }
        }
    cout<<t<<endl;
    }
    return 0;
}

