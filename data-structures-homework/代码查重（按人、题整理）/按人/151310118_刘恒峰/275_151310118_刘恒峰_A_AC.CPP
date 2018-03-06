#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <queue>
#include <list>
#include <cstring>
#include <cmath>


using namespace std;

priority_queue<int ,vector<int>,greater<int> >moneyque;
priority_queue<int ,vector<int>,less<int> >moneyques;


int main()
{
    long long int total;
    int n,m,money;
    int cnt;
    while (cin>>n>>m)
    {
        total=m;
        cnt=0;
        for (int i=0;i<n;i++)
        {
            cin>>money;
            if (money<0)
            {
                cnt++;
                moneyques.push(money);
            }
            else if (money!=0)
            {
                moneyque.push(money);
            }
        }
        if (cnt%2!=0)
        {
            moneyques.pop();
        }
        while (!moneyque.empty())
        {
            total*=moneyque.top();
            moneyque.pop();
        }
        while (!moneyques.empty())
        {
            total*=moneyques.top();
            moneyques.pop();
        }
        cout<<total<<endl;

    }
    return 0;
}

