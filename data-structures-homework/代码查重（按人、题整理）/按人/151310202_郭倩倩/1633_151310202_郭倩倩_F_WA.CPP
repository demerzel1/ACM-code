#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define max1 1000005
using namespace std;
struct note{
int left;
int right;
int weight;
note(int a=0,int b=0,int c=0):left(a),right(b),weight(c){}
friend bool operator<(note note1,note note2)
{
    return note1.weight<note2.weight;
}
};
vector<int>father;
vector<bool>root;
vector<note>usenote;
int weigh[max1];
int find_father(int x)
{
    int b=x;
    while(!root[b])
    {
        b=father[b];
    }
    return b;
}
void union_father(int a,int b)
{
    if(father[a]<father[b])
    {
        father[b]+=father[a];
        father[a]=b;
        root[a]=false;
    }
    else{
        father[a]+=father[b];
        father[b]=a;
        root[b]=false;
    }
}
int solve()
{
    int sum=0;
    for(int j=0;j<usenote.size();j++)
    {
        if(find_father(usenote[j].left)!=find_father(usenote[j].right))
       {
           union_father(find_father(usenote[j].left),find_father(usenote[j].right));
       sum+=usenote[j].weight;
       }
    }
   return sum;
}
int main()
{  int n,m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
       usenote.clear();
       father.clear();root.clear();
       father.resize(m+1);root.resize(m+1);
      for(int i=1;i<=m;i++)
      {
          father[i]=1;
          root[i]=true;
      }
      int k,l,p;
      for(int i=1;i<=n;i++)
      {
        scanf("%d%d%d",&k,&l,&p);
        usenote.push_back(note(k,l,p));
        weigh[i]=p;
      }
      sort(usenote.begin(),usenote.end());
     int ssun=solve(),susum=0,nk;
     for(int r=0;r<m-1;r++)
     {
       scanf("%d",&nk);
       susum+=weigh[nk];
     }
     if(ssun==susum) printf("YES\n");
     else printf("NO\n");
    }
    return 0;
}

