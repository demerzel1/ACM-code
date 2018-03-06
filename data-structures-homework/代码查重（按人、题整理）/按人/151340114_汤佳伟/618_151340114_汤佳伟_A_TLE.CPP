#include <iostream>
#include <queue>
#include <vector>
using namespace std;
///////////////////
struct mycompare{
bool operator()(const int& a, const int& b){
    if(a >= 0 && b >= 0)
        return a < b;
    else
        return a > b;

}
};
int main()
{
    int n, m;
    int e;
    long long int result;
    while(scanf("%d%d", &n, &m) ){
    priority_queue<int, vector<int>, mycompare> positive_queue;
    priority_queue<int, vector<int>, mycompare> negative_queue;

    for(int i = 1; i <= n; i++){
        scanf("%d", &e);
        if(e < 0)
            negative_queue.push(e);
        else
            positive_queue.push(e);
    }
    result = m;
    while(!positive_queue.empty()){
        e = positive_queue.top();
        if(e != 0)
            result *= e;
        positive_queue.pop();
    }
    int len = negative_queue.size();
    if(len % 2 == 0){
        while(!negative_queue.empty()){
            e = negative_queue.top();
            result *= e;
            negative_queue.pop();
        }
    }
    else{
        for(int i = 1; i < len; i++){
            e = negative_queue.top();
            result *= e;
            negative_queue.pop();
        }
    }


    printf("%lld\n", result);
}
    return 0;
}

