#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

class KikiGame
{
private:
    map <pair<int,int>,bool> hash;
    int mx,my;
public:
    void initial(int n,int m)
    {
        hash.clear();
        mx=n;
        my=m;
    }
    void process()
    {
        int n,a,b;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d%d",&a,&b);
            if (a>=1&&a<=mx&&b>=1&&b<=my)
            {
                pair <int,int> key;
                key.first=a;
                key.second=b;
                if (hash.find(key)==hash.end())
                {
                    hash[key]=true;
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
        }
    }
};

int main()
{
    int n,m;
    KikiGame kg;
    while (scanf("%d%d",&n,&m)!=-1)
    {
        kg.initial(n,m);
        kg.process();
    }
    return 0;
}

