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
    bool on;
    int n, fushu, minn;
    long long m, a[10];
    while(~scanf("%d%lld", &n, &m)){
        fushu=0, minn=-99, on=true;
        for(int i=1; i<=n; i++){
            scanf("%lld", &a[i]);
            if(a[i]<1){
                if(on){
                    if(on!=0){
                        if(a[i]!=0) fushu++;
                        //cout << a[i] << endl;
                        //if(a[i]>minn) minn=a[i];
                    }else on=false;
                }

            }
        }
        int funum=0;
        //cout << fushu << endl;
        if(fushu%2==0){
            for(int i=1; i<=n; i++){
                //cout << a[i] << endl;
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

