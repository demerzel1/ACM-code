#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

class node{
public:
    int x,y;
    node(int a=0,int b=0){x=a;y=b;}
};

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        int queCnt;
        map<int,bool> gMap;
        scanf("%d",&queCnt);
        for(int i=1;i<=queCnt;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            if(gMap.find(a*10+b)==gMap.end())
            {
                printf("YES\n");
                gMap[a*10+b]=true;
            }else{
                printf("NO\n");
            }
        }
    }
    return 0;
}

