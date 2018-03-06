#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int m,n;
typedef struct node{
	int l;
	int r;
	int Long;
}node;
node Tu[10000];
int Distance[105];
//int P[105];
int Solu(int a,int b)
{
     int i;
     for(i=1;i<=n;i++)
     {
        Distance[i]=0;
       // P[i]=0;
     }
     Distance[a]=2147483;
     int j;
     int k;
     int temp;
     for(i=1;i<n;i++)
     {
        for(j=0;j<2*m-1;j++)
        {
               temp=min(Distance[Tu[j].l],Tu[j].Long);
               if(temp>Distance[Tu[j].r])
                   Distance[Tu[j].r]=temp;
            }

        }
   //  cout<<Distance[b]<<endl;
     return Distance[b];
  }
int main()
{
	int g=0;
   scanf("%d%d",&n,&m);
   while(n&&m)
   {
   	     g++;

       int i=0;
       int a,b,temp;
       for(;i<2*m;i++)
       {
           scanf("%d%d%d",&a,&b,&temp);
           Tu[i].l=a;
           Tu[i].r=b;
           Tu[i].Long=temp;
           i++;
           Tu[i].l=b;
           Tu[i].r=a;
           Tu[i].Long=temp;
       }
       scanf("%d%d%d",&a,&b,&temp);
       int L=Solu(a,b);
       printf("d=%d\n",L);
       cout<<"Scenario #"<<g<<endl;
       cout<<"Minimum Number of Trips = ";
       if(temp%(L-1))
       {
    //   	cout<<"%%";
       	  cout<<int(temp/(L-1))+1<<endl;
	   }
	   else
	   {
	   	  cout<<int(temp/(L-1))<<endl;
	   }
	   cout<<endl;
       scanf("%d%d",&n,&m);
   }


  return 0;
}
