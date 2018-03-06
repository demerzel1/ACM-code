#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

#define Max 1000010

using namespace std;

int main()
{
    int n, m;
   while(scanf("%d%d", &n, &m) != EOF){
    int num1[Max] = {0};
    int num2[Max] = {0};
    int numberofchess;
    int x, y;
    scanf("%d", &numberofchess);
    for(int i(0); i<numberofchess; i++){
        scanf("%d%d", &x, &y);
        if((!num1[x] || !num2[y]) && x>=1 && x<=n && y>=1 && y<=m) {
                printf("YES\n");
                num1[x] = 1;
                num2[y] = 1;
        }
        else printf("NO\n");
    }
   }
   //map<int, int> mymap;

    return 0;
}

