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
        unsigned  sum=0;
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
        }
        sort(k.begin(),k.end());
        for(int i=0;i<n;i++)
        {
            vector<int>::iterator it;
            it=lower_bound(a.begin(),a.end(),k[i]);
            int q=*it;
            int p=*(it-1);
            q-=k[i];
            p-=k[i];
            sum+=min(fabs(q),fabs(p));
            if(fabs(q)>=fabs(p))
                a.erase(it);
        }
        printf("%d\n",sum);
    }
}

