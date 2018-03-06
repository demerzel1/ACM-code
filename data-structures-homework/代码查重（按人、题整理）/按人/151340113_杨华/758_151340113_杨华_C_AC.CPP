#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class KiKisGame{
private:
    int n,m,q;
    vector<vector<int> >chess;
public:
    void initial(int a,int b,int c);
    void computing();
};
void KiKisGame::initial(int a,int b,int c){
    n = a;
    m = b;
    q = c;
    chess.clear();
    chess.resize(n+1);
}
void KiKisGame::computing(){
    int x,y;
    for(int i = 1;i <= q;i++){
        scanf("%d %d",&x,&y);
        if(find(chess[x].begin(),chess[x].end(),y) == chess[x].end()){
            chess[x].push_back(y);
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}

int main()
{
    KiKisGame kkg;
    int n,m,q;
    while(scanf("%d %d",&n,&m) != EOF){
        scanf("%d",&q);
        kkg.initial(n,m,q);
        kkg.computing();
    }
    return 0;
}
