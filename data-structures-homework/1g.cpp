#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;
long num[10005];
int main()
{
    int n,c = 0;
    while (scanf("%d",&n)!=EOF) {
        num[c++] = n;
        sort(num,num+c);
        if (c%2!=0)
            printf("%d\n",num[c/2]);
        else
            printf("%d\n",(num[c/2]+num[c/2-1])/2);
    }
    return 0;
}
