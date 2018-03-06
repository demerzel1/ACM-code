#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int pileCnt;
    while(scanf("%d",&pileCnt)!=EOF)
    {
        priority_queue<int,vector<int>,greater<int>> que;
        for(int i=1;i<=pileCnt;i++){
            int n;
            scanf("%d",&n);
            que.push(n);
        }

        int res=0;
        if(que.size()==1) res+=que.top();
        while(que.size()!=1){
            int a,b;
            a=que.top();
            que.pop();
            b=que.top();
            que.pop();
            res+=a+b;
            que.push(a+b);
        }
        printf("%d\n",res);
    }

    return 0;
}

