#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int i,m,a[15],sum,n;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        a[0]=n;
        for(i=1;i<=m;i++)cin>>a[i];

        for(i=0,sum=1;i<=m;i++)
        {
            sum=sum*a[i];
            if(sum==0)
            {
            sum=n;
            break;
            }
            else if(sum>0)
            {
            n=sum;
            }
        }
    cout<<n<<endl;
    }
    return 0;
}

