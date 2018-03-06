#include <cstring>
using namespace std;

const int maxn=1100000;

int prime[maxn],primesize,phi[maxn];
bool isprime[maxn];
void getlist(int listsize)
{
    memset(isprime,1,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i])prime[++primesize]=i;
         for(int j=1;j<=primesize&&i*prime[j]<=listsize;j++)
         {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)break;
        }
    }
}
