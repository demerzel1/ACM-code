#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, Q, x, y;
    while(scanf("%d%d", &n, &m) != EOF){
        scanf("%d", &Q);
        vector<vector<int>> chess;
        chess.resize(n);
        for(int i = 0; i < n; i++){
            chess[i].resize(m, 0);
        }


        while(Q){
            scanf("%d%d", &x, &y);
            if(!chess[x-1][y-1]){
                printf("YES\n");
                chess[x-1][y-1] = 1;
            }
            else
                printf("NO\n");
            Q--;
        }


    }
    return 0;
}

