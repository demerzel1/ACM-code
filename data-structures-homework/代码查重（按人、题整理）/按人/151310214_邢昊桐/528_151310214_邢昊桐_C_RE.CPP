#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>
#include <hash_map>

using namespace std;

int X[100000];
int Y[100000];
int N,M;
int x,y;
int main()
{
    while(cin>>N>>M)
    {
        memset(X,0,sizeof(X));
        memset(Y,0,sizeof(Y));
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            cin>>x>>y;
            if(X[x]&&Y[y]) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
            X[x]=1;Y[y]=1;
        }
    }

    return 0;
}

