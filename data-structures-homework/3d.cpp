#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

long long qpow(long long a, int b){
    long long c, d; c = 1; d = a;
    while (b > 0){
        if (b & 1)
          c *= d;
        b = b >> 1;
        d = d * d;
    }
    return c;
}

int main()
{
    long long k;
    int c=0;
    while(1){
        scanf("%lld",&k);
        if(k==0)
            break;
        c=0;
        long long t=(long long)sqrt(k);
        if(t*t==k)
            c+=(t-1)/2;
        for(int z=3;z<31;z++)
        {
            for(long long x=1;;x++)
            {
                long long u=pow(x,z);
                if(u*2>=k)
                    break;
                for(long long y=x+1;;y++)
                {
                    long long v=pow(y,z);
                    if(u+v+x*y*z>k)
                        break;
                    if(u+v+x*y*z==k)
                        c++;
                }
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
