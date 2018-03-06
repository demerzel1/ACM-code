#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

#define Max 110

using namespace std;
int matrix[Max][Max];
int boy[Max];
int used[Max];
int numberofb, numberofg;

bool Find(int t){
for(int i(1); i<=numberofg; i++){
    if(!used[i] && matrix[t][i]){
        used[i] = 1;
        if(!boy[i] || Find(boy[i])){
            boy[i] = t;
            return true;
        }
    }
}
return false;

}

int main()
{
    while(scanf("%d%d", &numberofb, &numberofg)!=EOF){
            memset(matrix, 0, sizeof(matrix));
    memset(used, 0, sizeof(used));
    memset(boy, 0, sizeof(boy));
        int numberofline;
        int n, m;
            scanf("%d", &numberofline);
            for(int i(1); i<=numberofline; i++){
                    scanf("%d%d", &n, &m);
                    matrix[n][m] = 1;
            }
            int Sum(0);
            for(int i(1); i<=numberofb; i++){
                 if(Find(i)) Sum ++;
            }

            cout << Sum << endl;
          }


    return 0;
}



