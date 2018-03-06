#include <queue>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

priority_queue<int,vector<int>,greater<int> >mypq;

int n;
int sum;

int main()
{
    while(EOF!=scanf("%d",&n)){
        for(int i=0;i<n;i++){
            int temp;
            scanf("%d",&temp);
            mypq.push(temp);
        }
        sum=0;
        while(mypq.size()>1){
            int t1=mypq.top();
            mypq.pop();
            int t2=mypq.top();
            mypq.pop();
            sum+=t1+t2;
            if(!mypq.empty())mypq.push(t1+t2);
        }
        printf("%d\n",sum);
    }
    return 0;
}

