#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int maxn = 100005;
#define LL long long
int a[maxn];
map<LL,int>mp;
int res = 0;
int main()
{
     int n;
	 scanf("%d",&n);
     LL sum = 0;
	 for(int i = 1;i<=n;i++)
	 {
	      scanf("%d",&a[i]);
		  sum+=a[i];
		  res = max(res,++mp[sum]);
	 }
	 printf("%d\n",n-res);

}
