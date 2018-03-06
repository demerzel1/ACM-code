#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxsize=1000005;

class KMP
{
private:
    static char find[maxsize];
    static char original[maxsize];
    static int ind[maxsize];
    static int next[maxsize];
    void getnext()
    {
        for (int i=1;find[i]!='\0';i++)
        {
            int j=next[i];
            while(j>0&&find[i]!=find[j])
            {
                j=next[j];
            }
            if (find[i]==find[j])
            {
                next[i+1]=j+1;
            }
        }
    }
    int search()
    {
        int j=0,count=0;
        for (int i=0;original[i]!='\0';i++)
        {
            while (j>0&&original[i]!=find[j])
            {
                j=next[j];

            }
            if (original[i]==find[j])
            {
                j++;
            }
            if (find[j]=='\0')
            {
                ind[count++]=i-j+1+1;
                j=next[j];
            }
        }
        return count;
    }
public:
    void initial()
    {
        memset(next,0,sizeof(next));
    }
    void readCase(int n)
    {
        getchar();
        for (int i=0;i<n;i++)
        {
            scanf("%c",&original[i]);
        }
        original[n]='\0';
        scanf("%d",&n);
        getchar();
        for (int i=0;i<n;i++)
        {
            scanf("%c",&find[i]);
        }
        find[n]='\0';
    }
    void computing()
    {
        getnext();
    }
    void outResult()
    {
        int c=search();
        printf("%d\n",c);
        for (int i=0;i<c&&i<999;i++)
        {
            printf(" ");
            printf("%d",ind[i]);
        }
        printf("\n");
    }
};

char KMP::find[maxsize];
char KMP::original[maxsize];
int KMP::ind[maxsize];
int KMP::next[maxsize];

int main()
{
    int n;
    KMP kmp;
    while (scanf("%d",&n)!=-1)
    {
        kmp.initial();
        kmp.readCase(n);
        kmp.computing();
        kmp.outResult();
    }
    return 0;
}

