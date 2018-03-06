#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
////////////////
int main()
{
    int n, m;
    int e;
    int temp;
    long long int result = 0;
    vector<int>::iterator it;
    vector<int>::iterator it2;
    while(scanf("%d%d", &n, &m) != EOF){
        result = 0;
        temp = n;
        vector<int> friends;
        vector<int> gameleval;
        while(m--){
            scanf("%d", &e);
            friends.push_back(e);
        }
        while(temp--){
            scanf("%d", &e);
            gameleval.push_back(e);
        }
        sort(friends.begin(), friends.end());
        while(n--){
            it = lower_bound(friends.begin(), friends.end(), gameleval[n]);
            if(it == friends.begin()){
                result += abs(*it - gameleval[n]);
                continue;
            }
            if(it == friends.end()){
                result += abs(*(--it) - gameleval[n]);
                continue;
            }
            it2 = it;
            it--;
            if(abs(*it - gameleval[n]) <= abs(*it2 - gameleval[n]))
               result += abs(*it - gameleval[n]);
            else
                result += abs(*it2 - gameleval[n]);

        }
        printf("%lld\n", result);

    }
    return 0;
}

