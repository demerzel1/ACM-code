#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool cmp(int a,int b)
{
    return a > b;
}

int main()
{
    int i,j,n,m,a;
    vector<int> b;
    while(cin >> n >> m)
    {
        b.clear();
        b.push_back(m);
        for(i = 1;i <= n;i++)
        {
            cin >> a;
            for(j = 0;j < b.size();j++)
            {
                int tem = b[j] * a;
                b.push_back(tem);
            }
        }
        sort(b.begin(),b.end(),cmp);
        cout << b[0] << endl;
    }
    return 0;
}

