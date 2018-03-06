#include <iostream>
#include <queue>
using namespace std;
///////////////////
struct mycompare{
bool operator()(const int& a, const int& b){
    return a > b;
}
};
int main()
{
    int n;
    int e;
    long long int result;
    while(scanf("%d", &n) != EOF ){
    priority_queue<int, vector<int>, mycompare> pile;
    result = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &e);
        pile.push(e);

    }
    while(!pile.empty()){
        e = 0;//initial
        e += pile.top();
        pile.pop();
        e += pile.top();
        pile.pop();
        result += e;
        if(!pile.empty())
            pile.push(e);

    }



    printf("%lld\n", result);
}
    return 0;
}

