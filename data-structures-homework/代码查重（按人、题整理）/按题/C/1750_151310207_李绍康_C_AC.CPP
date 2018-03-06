#include <iostream>
#include <map>

using namespace std;

int main()
{
    int i,n,m,q;
    string s;
    map<string,int> a;
    while(cin >> n >> m)
    {
        a.clear();
        cin >> q;
        cin.ignore(256,'\n');
        for(i = 0;i < q;i++)
        {
            getline(cin,s);
            if(a.count(s) == 0)
            {
                cout << "YES" << endl;
                a[s] = 1;
            }
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}

