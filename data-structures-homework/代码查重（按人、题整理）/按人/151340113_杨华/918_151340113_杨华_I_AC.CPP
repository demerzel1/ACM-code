#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

class NewtonandApple{
private:
    priority_queue<int,vector<int>,greater<int> >pile;
    long long result;
    int n;
public:
    void initail(int N);
    void read();
    void computing();
    void outresult();
};
void NewtonandApple::initail(int N){
    n = N;
    result = 0;
    while(!pile.empty()){
        pile.pop();
    }
}
void NewtonandApple::read(){
    int temp;
    for(int i = 0;i < n;i++){
        scanf("%d",&temp);
        pile.push(temp);
    }
}
void NewtonandApple::computing(){
    int p1,p2;
    int p;
    while(pile.size() > 1){
        p1 = pile.top();
        pile.pop();
        p2 = pile.top();
        pile.pop();
        p = p1 + p2;
        result += p;
        pile.push(p);
    }
}
void NewtonandApple::outresult(){
    printf("%lld\n",result);
}

int main()
{
    NewtonandApple nta;
    int n;
    while(scanf("%d",&n) != EOF){
        nta.initail(n);
        nta.read();
        nta.computing();
        nta.outresult();
    }
    return 0;
}
