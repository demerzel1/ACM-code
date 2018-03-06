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
    int gameCnt,iniMoney;
    while(scanf("%d %d",&gameCnt,&iniMoney)!=EOF){
        int maxx=-1000;
        int sum=0;
        int cnt=0;
        int id;
        int a[12]={0};
        for(int i=0;i<gameCnt;i++){
            scanf("%d",&a[i]);
            if(a[i]<0) cnt++;
        }
        for(int i=0;i<gameCnt;i++){
            if(a[i]<0 && a[i]>maxx){
                id=i;
                maxx=a[i];
                }
  
        }

        if(cnt%2!=0)
            for(int i=0;i<gameCnt;i++){
                if(id!=i) iniMoney*=a[i];
            }
        else
            for(int i=0;i<gameCnt;i++){
                iniMoney*=a[i];
            }

        printf("%d\n",iniMoney);
    }
    return 0;
}

