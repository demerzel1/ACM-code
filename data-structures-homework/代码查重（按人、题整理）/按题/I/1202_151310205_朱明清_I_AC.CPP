#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

#define Max 100000

using namespace std;

int main()
{
    int numberofpile;
    while(scanf("%d", &numberofpile) !=EOF){
        priority_queue<int, vector<int>, greater<int> > Q;
        int n;
        for(int i(0); i<numberofpile; i++){
                scanf("%d", &n);
            Q.push(n);
        }
        int Sum(0);
        int s(0);
        int n1, n2;
        while(!Q.empty()){
            n1 = Q.top();
            Q.pop();
            n2 = Q.top();
            Q.pop();
            s = n1+n2;
            Sum += s;
            if(Q.empty()) break;
            Q.push(s);

        }
        cout << Sum << endl;
    }


    return 0;
}



