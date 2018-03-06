#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int x;
    int y;
    friend bool operator == (node n1,node n2){
        return (n1.x == n2.x && n1.y == n2.y);
    }
};

class KiKisGame{
private:
    int n,m,q;
    vector<node>no;
public:
    void initial(int a,int b,int c);
    void computing();
};
void KiKisGame::initial(int a,int b,int c){
    n = a;
    m = b;
    q = c;
    no.clear();
}
void KiKisGame::computing(){
    int x,y;
    node n1;
    for(int i = 1;i <= q;i++){
        scanf("%d %d",&x,&y);
        n1.x = x;
        n1.y = y;
        if(find(no.begin(),no.end(),n1) != no.end()){
            printf("NO\n");
        }
        else{
            no.push_back(n1);
            printf("YES\n");
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
