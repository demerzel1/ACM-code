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
            if(x>n||y>m)
                printf("NO\n");
            else
            {
                if(v[x].empty())
                {
                    printf("YES\n");
                    v[x].push_back(y);
                }
                else
                    for(int i=0;i<v[x].size();i++)
                    if(v[x][i]==y)
                     {
                           printf("NO\n");
                           break;
                     }

                    else
                    {
                        printf("YES\n");
                        v[x].push_back(y);
                        break;
                    }
            }

        }
    }
    return 0;
}

