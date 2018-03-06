//9

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1000005;



int main()
{
    int n;
    while(~scanf("%d",&n)){
        priority_queue<int,vector<int>,greater<int> > que;
        for(int i=0;i<n;i++){
            int cpy;scanf("%d",&cpy);
            que.push(cpy);
        }

        int sum=0;
        while(que.size()!=1){
            int num1 = que.top();
            que.pop();
            int num2 = que.top();
            que.pop();

            sum += num1+num2;
            que.push(num1+num2);
        }
        cout<<sum<<endl;
    }
    return 0;
}

