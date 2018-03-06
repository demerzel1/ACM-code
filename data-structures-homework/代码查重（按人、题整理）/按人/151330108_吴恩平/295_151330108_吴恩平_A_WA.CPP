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
    int n, m, sum, fushu, min;
    vector<int> a;
    while(~scanf("%d%d", &n, &m)){
        a.clear(), a.push_back(0);
        sum=0, fushu=0, min=-11;
        for(int i=1; i<=n; i++){
            a.push_back(0);
            scanf("%d", &a.at(i));
            if(a.at(i)<0){
                fushu++;
                if(a.at(i)>min) min=a.at(i);
            }
        }
        if(m<0){
            if(fushu%2==0){
                for(int i=1; i<=n; i++){
                    if(a[i]!=0 && a[i]!=min) m=m*a[i];
                }
            }else{
                for(int i=1; i<=n; i++)
                    if(a[i]!=0) m=m*a[i];
            }
        }else{
            if(fushu%2==0){
                for(int i=1; i<=n; i++)
                    if(a[i]!=0) m=m*a[i];
            }else{
                for(int i=1; i<=n; i++){
                    if(a[i]!=0 && a[i]!=min) m=m*a[i];
                }
            }
        }
        printf("%d\n", m);
    }


    return 0;
}

