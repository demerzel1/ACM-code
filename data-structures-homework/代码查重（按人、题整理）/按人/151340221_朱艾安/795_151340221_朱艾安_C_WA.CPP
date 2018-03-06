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
bool x[1000100]={0};
bool y[1000100]={0};
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        int queCnt;
        scanf("%d",&queCnt);
        for(int i=1;i<=queCnt;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            if(!x[a] || !y[b] ){
                x[a]=y[b]=true;
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
        memset(x,false,sizeof(x));
        memset(y,false,sizeof(y));
    }
    return 0;
}

