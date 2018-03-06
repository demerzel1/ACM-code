#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int n,m;
typedef struct Eage{
   int l;
   int r;
   int co;
   int c;
}Eage;
vector<Eage> S;
int Parent[1005];
vector<int> F;
vector<int> FF;
bool cmp(Eage a,Eage b)
{
    return  a.co<b.co;
}
int Pa(int a)
{
    while(Parent[a])
    {
        a=Parent[a];
    }
    return a;
}
int main()
{
   // cout<<"nfweibbn"<<endl;
    int i,j;
    int x,y,z;
    Eage temp;
   while(scanf("%d%d",&n,&m)!=EOF)
   {
       fill(Parent,Parent+1003,0);
       for(i=1;i<=m;i++)
       {
           scanf("%d%d%d",&x,&y,&z);
           temp.l=x;
           temp.r=y;
           temp.co=z;
           temp.c=i;
           S.push_back(temp);
        //   cout<<i<<endl;
         /*  temp.l=y;
           temp.r=x;
           S.push_back(temp);*/
       }
       int a,b;
       int c,d;
       sort(S.begin(),S.end(),cmp);
       for(i=0;i<S.size();i++)
       {
           temp=S[i];
           a=temp.l;
           b=temp.r;
           c=Pa(a);
           d=Pa(b);
           if(c!=d)
           {
               Parent[c]=d;
               F.push_back(temp.c);
           }
       }
       sort(F.begin(),F.end());
     //  cout<<"wbfeiu"<<endl;
       for(i=1;i<=n-1;i++)
       {
           scanf("%d",&a);
           FF.push_back(a);
       }
       sort(FF.begin(),FF.end());
       bool flag=true;;
       if(F.size()==FF.size())
       {
           for(i=0;i<F.size();i++)
            if(F[i]!=FF[i])
              {
                  flag=false;
                  break;
              }
       }
       else
        flag=false;
       if(flag)
        printf("YES\n");
       else
        printf("NO\n");
       F.clear();
       FF.clear();
       S.clear();
   }
  return 0;
}

