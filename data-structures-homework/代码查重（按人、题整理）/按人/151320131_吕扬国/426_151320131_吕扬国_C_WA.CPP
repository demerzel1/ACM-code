#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
map<int,int> m1;
map<int,int> m2;
map<int,int>::iterator it1,it2;
int m,n,q,x,y;
int main()
{
    while(cin>>m>>n)
    {
        m1.clear();
        m2.clear();
        cin>>q;
        while(q--)
        {
            cin>>x>>y;
            it1=m1.find(x);
            it2=m2.find(y);
            if(it1==m1.end()||it2==m2.end()) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            m1[x]=1;
            m2[y]=1;
        }
    }
    return 0;
}

