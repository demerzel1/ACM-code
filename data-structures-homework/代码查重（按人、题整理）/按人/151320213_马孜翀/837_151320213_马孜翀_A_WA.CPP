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
        int b=n;
        int c=n;
        sum=m;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==0)
                b=i;
        }

        for(int i=0;i<b;i++)
        {
            if(a[i]<0)
            {
                con++;
                c=i;
            }
        }
        if(con%2==0)
        for(int i=0;i<b;i++)
        {
            sum*=a[i];
        }
        else
        for(int i=0;i<c;i++)
        {
            sum*=a[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}

