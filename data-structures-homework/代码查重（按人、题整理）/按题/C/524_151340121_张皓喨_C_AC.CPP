#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;
map <int , map<int, bool> > p ;
int main()
{
     int n,t, m, mn ,x,y,q;
     while (cin >>n >>m){
        mn=0 ; t=m;
        cin >>q;
        p.clear();
       /// memset(p,true,sizeof(p) );
       /// a.clear();
       for (int h=0; h<q ; h++){
        cin >>x >>y;
        if ( p[x][y] ) cout << "NO" << endl;
        else {
            p[x][y] = true ;
            cout << "YES" << endl;
        }
       }
        ;

     }

    return 0;
}

