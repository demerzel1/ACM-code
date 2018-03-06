#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,m,x,num;
    vector<int>a;
    vector<int>b;
    while(cin>>n>>m)
    {
        a.clear();
        b.clear();
        int result = m;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x>0)
                a.push_back(x);
            if(x<0)
                b.push_back(x);
        }
        if(b.size()%2!=0)
        {
            sort(b.begin(),b.end());
            for(int i=0;i<b.size()-1;i++)
                result *= b[i];
        }
        else
        {
            for(int i=0;i<b.size();i++)
            {
                result *=b[i];
            }
        }
        for(int i=0;i<a.size();i++)
            result*=a[i];
        cout<<result<<endl;
    }
}

