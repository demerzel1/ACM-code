#include <iostream>

using namespace std;

int main()
{

    int n,m;
    while(cin>>n>>m)
    {
        int a[10]={0};
        for(int i=0;i<n;i++)
            cin>>a[i];
        int count1=0;
        for(int i=0;i<n;i++){
            if(a[i]<0)
                count1++;
        }
        if(count1%2==0)
        {
            for(int i=0;i<n;i++)
                if(a[i]!=0)
                m*=a[i];
            cout<<m<<endl;
        }else{
            int mm=-9999999;
            for(int i=0;i<n;i++){
                if(a[i]!=0)
                m*=a[i];
                if(a[i]<0&&a[i]>mm)
                    mm=a[i];
            }
                cout<<m/mm<<endl;

        }

    }
    return 0;
}

