#include <iostream>
#include <map>
using namespace std;
struct cor{
    int x;
    int y;
};
struct com{
    bool operator()(const cor & a, const cor & b){
        if(a.x > b.x)
            return true;
        else if(a.x < b.x){
            return false;
        }
        else
            return a.y > b.y;
    }
};
int main()
{
    map<cor, bool, com> chess;
    int n, m, Q, x, y;
    struct cor e;
    while(scanf("%d%d", &n, &m) != EOF){
        scanf("%d", &Q);
        while(Q){
            scanf("%d%d", &x, &y);
            e.x = x;
            e.y = y;

            if(chess.insert(pair<cor, bool>(e, true)).second == true){
                printf("YES\n");
            }
            else
                printf("NO\n");
            Q--;
        }


    }
    return 0;
}

