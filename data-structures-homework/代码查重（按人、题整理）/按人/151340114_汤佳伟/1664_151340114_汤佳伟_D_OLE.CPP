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
            it = lower_bound(friends.begin(), friends.end(), gameleval[n-1]);
            it2 = it;
            it--;
            cout<<abs(*it - gameleval[n-1])<<"  "<<abs(*it2 - gameleval[n-1])<<'\n';
            if(abs(*it - gameleval[n-1]) <= abs(*it2 - gameleval[n-1]))
               result += abs(*it - gameleval[n-1]);
            else
                result += abs(*it2 - gameleval[n-1]);

        }
        printf("%lld", result);

    }
    return 0;
}

