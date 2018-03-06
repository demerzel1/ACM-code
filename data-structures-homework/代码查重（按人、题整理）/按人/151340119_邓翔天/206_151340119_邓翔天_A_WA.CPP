#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
long long turn,mon;
long long ele[100];
long long maxmon;
int main()
{
    while(EOF!=scanf("%lld%lld",&turn,&mon)){
            maxmon=mon;
        for(int i=0;i<turn;i++){
            scanf("%lld",&ele[i]);
        }
        long long t_mon=mon;
        for(int i=0;i<turn;i++){
            t_mon*=ele[i];
            if(t_mon>maxmon) maxmon=t_mon;
        }
        printf("%lld\n",maxmon);
    }
    return 0;
}

