#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;


class ImpresstheGoddess
{
private:
    string s;
    string p;
    vector<int>next;
    vector<int>result;
    void getNext();
    void KMP();
public:
    void initial(int);
    void readCase();
    void computing();
    void outResult();
};
void ImpresstheGoddess::initial(int n)
{
    s.clear();
    s.resize(n+1);
    p.clear();
    next.clear();
    result.clear();
}
void ImpresstheGoddess::readCase()
{
    getchar();
    getline(cin,s);
    //cout<<s<<endl;
    int m;
    scanf("%d",&m);
    getchar();
    p.resize(m+1);
    getline(cin,p);
    //cout<<p<<endl;
}
void ImpresstheGoddess::getNext()
{
    int i=0,j=-1;
    int t=p.size();
    next.resize(t);
    next[0]=-1;
    while(i<t-1)
    {
        if(j==-1||p[i]==p[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
    /*for(int i=0;i<next.size();i++)
        cout<<next[i]<<" ";*/
}
void ImpresstheGoddess::KMP()
{
    getNext();
    int i=0,j=0;
    int m=p.size(),n=s.size();
    while(i<n&&j<m)
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
        }
        else
            j=next[j];
        if(j==m)
        {
            int t=i-j+1;
            result.push_back(t);
            j=0;
            i=t;
            //printf("%d\n",i);
        }
    }
}
void ImpresstheGoddess::computing()
{
    KMP();
}
void ImpresstheGoddess::outResult()
{
    printf("%d\n",result.size());
    printf("%d",result[0]);
    for(int i=1; i<result.size(); i++)
        printf(" %d",result[i]);
    printf("\n");
}
int main()
{
    ImpresstheGoddess ig;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        ig.initial(n);
        ig.readCase();
        ig.computing();
        ig.outResult();
    }
    return 0;
}

