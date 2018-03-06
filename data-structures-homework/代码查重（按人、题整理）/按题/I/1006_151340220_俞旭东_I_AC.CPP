#include <iostream>
#include<queue>
using namespace std;

int main()
{
    int i;
    while(cin>>i)
    {
        int sum=0;
        priority_queue<int,vector<int>,greater<int> >p;
        while(!p.empty())
        p.pop();

        while(i--)
        {
            int q;
            cin>>q;
            p.push(q);
        }
        while(!p.empty()){
            int i=p.top();
            p.pop();
            int j=p.top();
            p.pop();
            i=i+j;
            if(p.empty())
            {
                 sum+=i;
                 break;
            }
            else
            {
                p.push(i);
                sum+=i;
            }


        }
          cout<<sum<<endl;
    }
    return 0;
}

