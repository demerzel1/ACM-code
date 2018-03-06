#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a;
vector <int> g; /// negative
int main()
{
    int n,t, m, mn,p; /// most
    while (cin >>n >>m){
        mn=0 ; t=m;
        a.clear();
        for (int h=0; h<n; h++){
            cin >> p;
            a.push_back(p);
            if(p<0) g.push_back(p);
           if (a[h] !=0 ) t= t*a[h];
        }
        mn=t;
            if (t>0) mn=t;
            else {
                for ( unsigned h=0; h<g.size(); h++){
                         for ( unsigned j=0; j< g.size(); j++){
                    p= max(g[h],g[j]) ;
                         }
                }
               mn /= p ;
            }
        ;
        cout << mn << endl;
    }

    return 0;
}


