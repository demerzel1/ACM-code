#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define max1 1000010
using namespace std;

struct note{
int x;
int y;
note(int a=0,int b=0):x(a),y(b){}
friend bool operator ==(note note1,note note2)
{
    if(note1.x==note2.x&&note1.y==note2.y)
        return true;
    else {return false;}
}
};vector<note >usenote[max1];
int main()
{
   int n,m;
   while(scanf("%d%d",&n,&m)!=EOF)
   {
    int q,x1,y1;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
       scanf("%d%d",&x1,&y1);
       int c=0;
      for(int i=0;i<usenote[x1].size();i++)
          { if(note(x1,y1)==usenote[x1][i])
          {
             printf("NO\n");
             c=1;
             break;
          }}
          if(c==0)
            {usenote[x1].push_back(note(x1,y1));
             printf("YES\n");
            }
    }
   }
    return 0;
}

