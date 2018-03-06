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
        if(num%2==0)
        {
            for(int i=0;i<a.size();i++)
            {
                result = result*a[i];
            }
        }
        else
        {
            int i;
            for(i =n-1;i>=0;i--)
            {
                if(a[i]<0)
                    break;
            }
            for(int j=0;j<i;j++)
            {
                result = result*a[j];
            }
        }
        cout<<result<<endl;
    }
}

