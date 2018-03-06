#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n, fushu, minn, on;
    long long m, a[10];
    while(~scanf("%d%lld", &n, &m)){
        fushu=0, minn=-99, on=-1;
        for(int i=1; i<=n; i++){
            scanf("%lld", &a[i]);
            if(a[i]<1){
                if(on==-1){
                    if(on!=0){
                        fushu++;
                        if(a[i]>minn) minn=a[i];
                    }else on=i;
                }

            }
        }
        int funum=0;
        if(fushu%2==0){
            for(int i=1; i<=n; i++){
                if(a[i]==0) break;
                m=m*a[i];
            }
        }else{
            for(int i=1; i<=n; i++){
                if(a[i]<0)funum++;
                if(funum==fushu) break;
                m=m*a[i];
            }
        }
        printf("%lld\n", m);
    }
    return 0;
}
/*
5 6
6 8 5 2 3
3 5
-9 -5 6
*/
