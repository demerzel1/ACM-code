#include <iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int m,n;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        vector<int> a,k;
        long long int sum=0;
        for(int i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            k.push_back(x);
            vector<int>::iterator it;
            it=lower_bound(a.begin(),a.end(),x);
            int q=*it;
            int p=*(it-1);
            q-=x;
            p-=x;
            sum+=min(fabs(q),fabs(p));
        }
        printf("%lld\n",sum);
    }
}

