#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class IntertestingGame{
private:
    int n;
    int a[9];
    vector<int>ra;
    int result;
public:
    void initial(int N,int M);
    void read();
    void computing();
    void outresult();
};
void IntertestingGame::initial(int N,int M){
    n = N;
    result = M;
    ra.clear();
}
void IntertestingGame::read(){
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
        if(a[i] < 0){
            ra.push_back(a[i]);
        }
    }
}
void IntertestingGame::computing(){
    if(ra.size() % 2 != 0){
        sort(ra.begin(),ra.end());
        int temp = ra.size() - 1;
        for(int i = 0;i < n;i++){
            if(a[i] == ra[temp]){
                a[i] = 0;
                break;
            }
        }
    }
    for(int i = 0;i < n;i++){
        if(a[i]){
            result = result * a[i];
        }
    }
}
void IntertestingGame::outresult(){
    printf("%d\n",result);
}

int main()
{
    IntertestingGame ig;
    int n,m;
    while(scanf("%d %d",&n,&m) != EOF){
        ig.initial(n,m);
        ig.read();
        ig.computing();
        ig.outresult();
    }
    return 0;
}
