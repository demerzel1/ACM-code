#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        priority_queue<int,vector<int>,greater<int>>piles;
        int sumcost=0;
        int pile;
        while(n--)
        {
            cin>>pile;
            piles.push(pile);
        }
        int l,l1,l2;
        while(piles.size()!=1)
        {
            l1=piles.top();
            piles.pop();
            l2=piles.top();
            piles.pop();
            l=l1+l2;
            sumcost+=l;
            piles.push(l);
        }
        piles.pop();
        cout<<sumcost<<endl;
    }
    return 0;
}

