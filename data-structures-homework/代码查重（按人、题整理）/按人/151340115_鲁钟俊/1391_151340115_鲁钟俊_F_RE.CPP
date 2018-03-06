#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <cstring>
#include <queue>
#include <sstream>

using namespace std;

priority_queue<int,vector<int>,greater<int> >  q1,q2;

int n,m;
int flag1,flag2;
int vset[105];

struct eage
{
    int x,y,w;
};

bool cmp(eage a,eage b)
{
    return a.w<b.w;
}

eage E[570000],E1[570000];


void input()
{
    for(int i=1;i<=n;i++)
    {
        vset[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>E[i].x>>E[i].y>>E[i].w;
        E1[i].x=E[i].x;
        E1[i].y=E[i].y;
        E1[i].w=E[i].w;
    }
    sort(E+1,E+m+1,cmp);
}

void compute()
{
    int t;
    while(!q1.empty())  q1.pop();
    while(!q2.empty())  q2.pop();
    for(int i=1;i<n;i++)
    {
        cin>>t;
        int n1=vset[E1[t].x];
        int n2=vset[E1[t].y];
        if(n1!=n2)
        {
            q1.push(E1[t].w);
            for(int j=1;j<=n;j++)
            {
                if(vset[j]==n2)
                    vset[j]=n1;
            }
        }
    }
    flag1=0,flag2=0;;
    for(int i=1;i<n;i++)
    {
            for(int j=i+1;j<=n;j++)
            {
                if(vset[i]!=vset[j])
                    {
                        flag1=1;
                        break;
                    }
            }
    }
    if(flag1==1)   cout<<"NO"<<endl;
    else
    {

    for(int i=1;i<=n;i++)
    {
        vset[i]=i;
    }
    for(int j=1;j<=m;j++)
    {
        int n1=vset[E[j].x];
        int n2=vset[E[j].y];
        if(n1!=n2)
        {
            q2.push(E[j].w);
            for(int i=1;i<=n;i++)
            {
                if(vset[i]==n2)
                    vset[i]=n1;
            }
        }
    }
    int cnt=q1.size();
    for(int j=1;j<=cnt;j++)
    {
        int ss1=q1.top();
        q1.pop();
        int ss2=q2.top();
        q2.pop();
        if(ss1!=ss2)
        {
            flag2=1;
            break;
        }
    }
    if(flag2==1)  cout<<"NO"<<endl;
    else         cout<<"YES"<<endl;
    }

}

int main()
{
    while(cin>>n>>m)
    {
        input();
        compute();
    }
    return 0;
}

