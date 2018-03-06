#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
    char str[1000005]={0};
    char ptr[1000005]={0};
    int slen,plen;
    int nex[1000005];
    int f[1000005];
void cal_next(char *str,int *next,int len)
{
    int i,j;
    next[0]=-1;
    for(i=1;i<len;i++)
    {
        j=next[i-1];
        while(str[j+1]!=str[i]&&j>=0)
        {
            j=next[j];
        }
        if(str[i]==str[j+1])
        {
            next[i]=j+1;
        }
        else {
            next[i]=-1;
        }
    }
}
int kmp(char *str,int slen,char *ptr,int plen,int *next)
{
    int s_i=0,p_i=0;
    while(s_i<slen&&p_i<plen)
    {
        if(str[s_i]==ptr[p_i])
        {
            s_i++;
            p_i++;
        }
        else {
            if(p_i==0)s_i++;
            else p_i=next[p_i-1]+1;
        }
    }
    return (p_i==plen)?(s_i-plen):-1;
}
int main()
{

    while(cin>>slen)
    {

        getchar();
        gets(str);
        cin>>plen;
        getchar();
        gets(ptr);
        int k=0,kk=0,kkk=0;
        cal_next(ptr,nex,plen);
        while(1)
        {
            if(slen-kkk<=0)break;
        kk=kmp(str+kkk,slen-kkk,ptr,plen,nex);
        if(kk>-1){f[k]=kk+1+kkk;k++;kkk=kkk+kk+1;}
        else break;
        }
        int xx=0;
        cout<<k<<endl;
        for(int i=0;i<k;i++)
        {
            if(xx) cout<<" ";
            cout<<f[i];
            xx=1;
        }
        cout<<endl;
    }
    return 0;
}

