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
int vset[105];

struct eage
{
    int x,y,w,id;
};

bool cmp(eage a,eage b)
{
    return a.w<b.w;
}

eage E[570000];


void input()
{
    for(int i=1;i<=n;i++)
    {
        vset[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>E[i].x>>E[i].y>>E[i].w;
        E[i].id=i;
    }
    sort(E+1,E+m+1,cmp);

}

void compute()
{
    int t;
    while(!q1.empty())  q1.pop();
    while(!q2.empty())  q2.pop();
    for(int i=0;i<n-1;i++)
    {
        cin>>t;
        int pos;
        for(int p=1;p<=m;p++)
        {
            if(E[p].id==t)
            {
                pos=p;
                //cout<<"id:"<<p<<endl;
                break;
            }
        }
        int n1=vset[E[pos].x];
        int n2=vset[E[pos].y];
        if(n1!=n2)
        {
            q1.push(E[pos].w);
            for(int j=1;j<=n;j++)
            {
                if(vset[j]==n2)
                    vset[j]=n1;
            }
        }
    }
    /*for(int i=1;i<n;i++)
    {
        cout<<"aaa"<<i<<":"<<vset[i]<<endl;
    }*/
    int flag1=0,flag2=0;;
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
    /*for(int j=1;j<=cnt;j++)
    {
        cout<<q1.top()<<" ";
        q1.pop();
    }
    cout<<endl;
    for(int j=1;j<=cnt;j++)
    {
        cout<<q2.top()<<" ";
        q2.pop();
    }
    cout<<endl;*/
    for(int j=1;j<=cnt;j++)
    {
        int ss1=q1.top();
        q1.pop();
        int ss2=q2.top();
        q2.pop();
        if(ss1!=ss2)
        {
            //cout<<"error"<<endl;
            flag2=1;
            break;
        }
    }
    if(flag1==1||flag2==1)  cout<<"NO"<<endl;
    else         cout<<"YES"<<endl;

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

