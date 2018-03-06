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
    long long n, m, funum, a[10], min;
    while(cin >> n >> m){
        min=-99, funum=0;
        bool on=true;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            if(a[i]<=0){
                funum++;
                if(a[i]!=0 && on){
                    funum++;
                    if(min<a[i]) min=a[i];
                }else on=false;
            }
        }
        if(funum%2==0)
            for(int i=1; i<=n; i++){
                if(a[i]!=0) m*=a[i];
                else break;
            }
        else{
            for(int i=1; i<=n; i++){
                if(a[i]!=0){
                    if(a[i]!=min) m*=a[i];
                }else break;
            }
        }
        cout << m << endl;
    }
    return 0;
}
/*
5 6
6 8 5 2 3
3 5
-9 -5 6
*/

