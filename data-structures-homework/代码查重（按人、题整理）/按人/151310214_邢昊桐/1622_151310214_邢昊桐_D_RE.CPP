#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
int N,M;
int nn,mm;
priority_queue<int,vector<int>,greater<int> >m;
priority_queue<int,vector<int>,greater<int> >n;
long long sum;
long long x;
void solu()
{
    for(int i=0; i<N; i++)
    {
        int a=n.top();
        x=a;
        n.pop();
        while(1)
        {
            int b=m.top();
            if(x>abs(b-a)) x=abs(b-a);
            else
            {
                sum+=x;
                break;
            }
            m.pop();
        }
    }
}

int main()
{
    while(cin>>N>>M)
    {
        while(m.size()) m.pop();
        while(n.size()) n.pop();
        for(int i=0; i<M; i++)
        {
            cin>>mm;
            m.push(mm);
        }
        for(int i=0; i<N; i++)
        {
            cin>>nn;
            n.push(nn);
        }
        sum=0;
        solu();
        cout<<sum<<endl;
    }
    return 0;
}

