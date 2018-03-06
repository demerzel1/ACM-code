//Code here
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    int FuCount;
    while(scanf("%d%d", &n, &m) != EOF){
            int num[9] = {0}, Sum(m);
            int Min(10);
            FuCount = 0;
        for(int i(0); i<n; i++){
            scanf("%d", &num[i]);
            if(num[i] < 0) {
                    FuCount++;
                    Min = Min > 0-num[i] ? 0-num[i] : Min;
                    //if(Min >= 0-num[i]) s = Min;
            }
            if(num[i] != 0) Sum *= num[i];

        }
       // cout<< Sum<< endl;
        //cout << FuCount << endl;
        //cout << Min << endl;
        if(FuCount){
            if(FuCount%2 == 0){
                  printf("%d\n", Sum);

            }
            else {

                printf("%d\n", Sum/(0-Min));
            }
        }
        else printf("%d\n", Sum);

    }
    return 0;
}

