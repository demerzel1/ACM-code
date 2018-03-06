#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

class NewtonAndApple{
    private:
        int numOfFruits, sum;
        priority_queue<int, vector<int>, greater<int> > p;
    public:
        void initial(int n)
        {
            numOfFruits=n, sum=0;
            while(!p.empty()) p.pop();
        }
        void readcase()
        {
            int num;
            for(int i=0; i<numOfFruits; i++){
                scanf("%d", &num);
                p.push(num);
            }
        }
        void computing()
        {
            if((int)p.size()==1) sum=0;
            else {
                while((int)p.size()>1){
                    int a=p.top();
                    p.pop();
                    int b=p.top();
                    p.pop();
                    sum+=a+b;
                    p.push(a+b);
                }
            }
        }
        void outresult()
        {
            printf("%d\n", sum);
        }
};

int main()
{
    int n;
    NewtonAndApple naa;
    while(~scanf("%d", &n)){
        naa.initial(n);
        naa.readcase();
        naa.computing();
        naa.outresult();
    }
    return 0;
}

