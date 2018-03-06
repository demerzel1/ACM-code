#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<int,int>mm;
map<int,int>::iterator it;
int a[100010];
int b[100010];

int main()
{
    int i,k,m,n,flag,t,sum,f;
    int low,high,mid;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
    for(i=0;i<n;i++)
    {
    cin>>k;
    mm[k]++;
    }
    for(i=0,it=mm.begin();it!=mm.end();it++,i++)
    {
    a[i]=it->first;
    }
    k=i-1;

    for(i=0;i<m;i++)
    {
    cin>>b[i];
    }

    for(sum=0,i=0;i<m;i++)
    {
    f=b[i];
    if(f<=a[0])sum=sum+a[0]-f;
    else if(f>=a[k])sum=sum+f-a[k];
    else
    {
        low=0;
        flag=0;
        high=k;
        while(low<=high)
        {
        t=low;
        mid=(low+high)/2;
        if(a[mid]<f)
            {
            low=mid+1;
            }
        else if(a[mid]>f)
            {
            high=mid-1;
            }
        else
        {
            flag=1;
            break;
        }
        }
        t=t-1;
        if(flag==0)
        {
            while(f-a[t]<0||a[t+1]-f<0)
            {
            t++;
            }
            if(f-a[t]>a[t+1]-f)
                sum=sum+a[t+1]-f;
            else sum=sum+f-a[t];
        }
    }
    }
    cout<<sum<<endl;
    mm.clear();
    }
    return 0;
}

