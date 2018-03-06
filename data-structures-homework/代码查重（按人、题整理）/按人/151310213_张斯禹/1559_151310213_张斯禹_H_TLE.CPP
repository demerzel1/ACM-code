#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <functional>
#include <cmath>
#include <memory.h>
#include <cstdio>
#include <sstream>
#include <set>

using namespace std;

vector <int> cal_next(vector<int>& small)
{
    int len=small.size();
    vector<int> nxt;
    for(int i=0;i<len;i++)
    {
        nxt.push_back(0);
    }
    for(int i=1,k=0;i<len;i++)
    {
        while(k>0&&small[i]!=small[k])
            k=nxt[k-1];
        if(small[i]==small[k])
            k++;
        nxt[i]=k;
    }
    return nxt;
}

int main()
{
    int m,n;
    while(cin>>m)
    {
        getchar();
        vector<int> line,small;
        char c;
        for(int i=0;i<m;i++)
        {
            scanf("%c",&c);
            line.push_back((int)c);
        }
        getchar();
        scanf("%d",&n);
        getchar();
        for(int i=0;i<n;i++)
        {
            scanf("%c",&c);
            small.push_back((int)c);
        }
        vector<int> nxt=cal_next(small);
        vector <int> output;
        int flag;
        for(int i=0;i<m-n+1;i++)
        {
            flag=0;
            for(int j=0;j<n;j++)
            {
                if(line[i+j]!=small[j])
                {
                    flag=1;
                    i+=nxt[j];
                    break;
                }
            }
            if(!flag)
                output.push_back(i+1);
        }
        cout<<output.size()<<endl;
        for(int i=0;i<output.size();i++)
        {
            if(i)
                cout<<" ";
            cout<<output[i];
        }
        cout<<endl;
    }
    return 0;
}

