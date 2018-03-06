#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int Next[1000005];
char a[1000005];
char b[1000000];
int n,m;
void getnext()
{
  //  getchar();
 //   getchar();
    int i=0;
    int j=-1;
   // cout<<m<<endl;
    Next[i]=j;
    while(i<m)
    {
     //   cout<<i<<endl;
        if(j==-1||b[i]==b[j])
        {
            i++;
            j++;
            Next[i]=j;
        }
        else{

            j=Next[j];
        }

    }

}
int main()
{
   while(scanf("%d",&n)!=EOF)
   {
       getchar();
       gets(a);
     //  cout<<a<<endl;
      // getchar();
       scanf("%d",&m);
       getchar();
       gets(b);
       getnext();
     //  cout<<n<<"  "<<m<<endl;
    //   cout<<"KKKKKKKKKKKKKKKKKKKkkk"<<endl;
       int i=0;
       int j=0;
       int num=0;
       int flag=1;
       while(i<n)
       {
           while(j<m&&i<n)
           {
          //     cout<<i<<"  "<<j<<endl;
            //0   getchar();
              // getchar();
               if(j==-1||a[i]==b[j])
               {
                   i++;
                   j++;
               }
               else{
                j=Next[j];
               }
           }
           if(j==m)
           {
               if(flag)
               {
                   flag=0;
                   printf("%d",i-j+1);
               }
               else
                printf(" %d",i-j+1);
               if(i<n)
              {
                 i=i-j+1;
                  j=0;
              }
           }
           else
            break;

       }
       printf("\n");
   }
   return 0;
}

