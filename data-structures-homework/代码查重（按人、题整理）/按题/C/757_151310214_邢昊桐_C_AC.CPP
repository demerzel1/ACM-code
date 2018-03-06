#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>
#include <hash_map>

using namespace std;
string str;
int N,M;
int x,y;
int main()
{
    while(cin>>N>>M)
    {
        map< string ,int >maps;

        int q;
        cin>>q;getchar();
        for(int i=0;i<q;i++)
        {

            getline(cin,str);
            if(maps.find(str)!=maps.end())
                cout<<"NO"<<endl;
            else
            {
                maps[str]=1;
                cout<<"YES"<<endl;
            }

        }
    }

    return 0;
}

