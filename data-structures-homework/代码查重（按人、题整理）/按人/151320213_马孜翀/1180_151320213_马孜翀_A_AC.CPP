#include <iostream>

using namespace std;

int main()
{
    int sum;
    int m,n;
    int a[20];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int con=0;
        int x=100;
        sum=m;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<0)
            {
                con++;
                if(x>-a[i])
                {
                    x=a[i];
                    x=-x;
                }
            }
        }
        if(con%2==0)
        for(int i=0;i<n;i++)
        {
            if(a[i]!=0)
            {
                sum*=a[i];
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(a[i]==-x)
                {
                      a[i]=0;
                      break;
                }
            }
            for(int i=0;i<n;i++)
            {
                if(a[i]!=0)
                {
                    sum*=a[i];
                }
            }
        }
        printf("%d\n",sum);
        sum=0;
        con=0;
        x=0;
    }
    return 0;
}

