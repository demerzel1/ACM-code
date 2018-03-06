#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

typedef pair<int,int>p;
map<p,int>m;
map<p,int>::iterator it;

int main()
{
    int i,t,h,n,x,y;
    while(scanf("%d%d",&h,&n)!=EOF)
    {
    cin>>t;
    for(i=0;i<t;i++)
    {
    scanf("%d%d",&x,&y);
    m[p(x,y)]++;
    if(m[p(x,y)]==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }
    m.clear();
    }
    return 0;
}

