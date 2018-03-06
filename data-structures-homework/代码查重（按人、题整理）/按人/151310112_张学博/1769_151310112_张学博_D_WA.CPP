#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <map>
#include <list>
#include <cstring>
#include <cmath>
using namespace std;
vector<int> a;
int n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        long long sum=0;
        a.resize(m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
        }
        int k,p,x;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            p=lower_bound(a.begin(),a.end(),x)-a.begin();
            k=upper_bound(a.begin(),a.end(),x)-a.begin();
            if(p==k)
            {
                sum+=min(abs(x-a[p]),abs(x-a[p-1]));
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}

