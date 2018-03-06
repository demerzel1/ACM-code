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
    int n, fushu, fushu1, min;
    long long m;
    vector<int> a;
    while(~scanf("%d%lld", &n, &m)){
        a.clear(), a.push_back(0);
        fushu=fushu1=0, min=-99;
        for(int i=1; i<=n; i++){
            a.push_back(0);
            scanf("%d", &a.at(i));
            if(a.at(i)<0){
                fushu++;
                if(a.at(i)>min) min=a.at(i);
            }
        }
        if(fushu%2==0){
            for(int i=1; i<=n; i++)
                if(a[i]!=0) m=m*a[i];
        }else{
            for(int i=1; i<=n; i++){
                if(a[i]!=0){
                    if(a[i]<0) fushu1++;
                    if(fushu1==fushu) break;
                    m=m*a[i];
                }
            }
        }
        printf("%lld\n", m);
    }
    return 0;
}

