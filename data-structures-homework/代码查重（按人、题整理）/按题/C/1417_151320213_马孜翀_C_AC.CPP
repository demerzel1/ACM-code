#include <iostream>
#include<map>
#include<vector>

using namespace std;

int main()
{

    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        vector<vector<int> > v;
        v.resize(n+1);
        int x,y;
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);
            if(v[x].empty())
            {
                printf("YES\n");
                v[x].push_back(y);
            }
            else
            {
                int flag=0;
                for(unsigned i=0;i<v[x].size();i++)
                {
                    if(v[x][i]==y)
                    {
                        flag=1;
                        printf("NO\n");
                        break;
                    }
                }
                if(flag==0)
                {
                    printf("YES\n");
                    v[x].push_back(y);
                }

            }

        }
    }
    return 0;
}

