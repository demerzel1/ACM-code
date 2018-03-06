#include <iostream>
#include <cstdio>
#include <cstring>
#define L 31500
using namespace std;
int l[L]={0};
int f(int x)
{
    long long sum=0;
    for(int i=1;;++i)
    {
        char t[10]={0};
        sprintf(t,"%d",i);
        l[i]=l[i-1]+strlen(t);
        if(sum+l[i]>=x)
            return x-sum;
        sum+=l[i];
    }
}
int  main()
{
    string str;
    for(int i=1;i<=L;++i)
    {
        char t[6]={0};
        sprintf(t,"%d",i);
        str+=t;
    }
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int a=f(n);
        cout<<str[a-1]<<endl;
    }
    return 0;
}
