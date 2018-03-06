#include <iostream>
#include <unordered_map>
#include <cstdio>

using namespace std;

class KikiGame
{
private:
    unordered_map <long long,bool> hash;
    int mx,my;
    int digit(int k)
    {
        int count=1;
        while (k/10)
        {
            count++;
        }
        return count;
    }
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
                long long key=a;
                for (int i=0;i<digit(b);i++)
                {
                    key*=10;
                }
                key+=b;
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

