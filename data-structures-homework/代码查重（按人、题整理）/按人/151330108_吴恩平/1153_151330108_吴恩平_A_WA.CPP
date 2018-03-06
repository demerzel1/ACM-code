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
    int n, fushu, minn;
    long long m, a[10];
    while(~scanf("%d%lld", &n, &m)){
        fushu=0, minn=-99;
        for(int i=1; i<=n; i++){
            scanf("%lld", &a[i]);
            if(a[i]<0){
                fushu++;
                if(a[i]>minn) minn=a[i];
            }
        }
        if(fushu%2==0){
            for(int i=1; i<=n; i++)
                if(a[i]!=0) m=m*a[i];
        }else{
            for(int i=1; i<=n; i++){
                if(a[i]!=0 && a[i]!=minn) m=m*a[i];
            }
        }
        printf("%lld\n", m);
    }
    return 0;
}

