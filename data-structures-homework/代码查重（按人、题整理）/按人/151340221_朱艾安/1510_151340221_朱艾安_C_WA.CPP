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

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        int queCnt;
        map<long long,bool> gMap;
        scanf("%d",&queCnt);
        for(int i=1;i<=queCnt;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            if(gMap.find((a-1)*n+b)==gMap.end())
            {
                printf("YES\n");
                gMap[(a-1)*n+b]=true;
            }else{
                printf("NO\n");
            }
        }
    }
    return 0;
}

