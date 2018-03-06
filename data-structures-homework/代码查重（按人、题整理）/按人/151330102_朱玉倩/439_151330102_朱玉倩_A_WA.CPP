#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,m,x,num;
    vector<int>a;
    while(cin>>n>>m)
    {
        a.clear();
        num=0;
        int result = m;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            a.push_back(x);
            if(x<0)
                num++;
        }
        if(num%2!=0)
        {
            for(int i=a.size()-1;i>=0;i--)
            {
                if(a[i]<0)
                {
                    for(int j=0;j<i;j++)
                    {
                        result*=a[j];
                    }
                    break;
                }
            }
        }
        else
        {
            for(int i=0;i<a.size();i++)
            {
                result *=a[i];
            }
        }
        cout<<result<<endl;
    }
}
