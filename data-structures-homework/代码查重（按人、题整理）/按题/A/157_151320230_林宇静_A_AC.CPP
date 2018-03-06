#include<iostream>
using namespace std;
int main()
{
    int n,m,a[20],sum;
    while(cin>>n>>m){
        int Max=-11;
        sum=m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==0)
                continue;
            if(a[i]<0){
                if(a[i]>Max)
                    Max=a[i];
            }
            sum*=a[i];
        }
        if(sum<0)
            sum=sum/Max;
        cout<<sum<<endl;
    }
    return 0;
}

