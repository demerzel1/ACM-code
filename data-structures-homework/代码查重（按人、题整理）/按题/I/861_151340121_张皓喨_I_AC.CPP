#include <iostream>
#include <queue>
int n,t,m;
using namespace std;
priority_queue <long long > p;
int main()
{   while (cin >> n){
    m= 0 ;
    while ( !p.empty() ) p.pop();
    for (int h=0; h< n ; h++){
        cin >> t;
        p.push(-t);
    }
    while (p.size() >=2 ){
        t = p.top();
        p.pop();
        t += p.top();
        p.pop();
        m += t;
        p.push(t);
    }
    m = -m ;
    cout << m << endl;
}

    return 0;
}

