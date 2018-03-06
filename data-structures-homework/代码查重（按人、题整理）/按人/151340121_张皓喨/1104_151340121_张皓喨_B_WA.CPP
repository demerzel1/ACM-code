#include <iostream>
#include <map>
#include <vector>
using namespace std;
int n,t,m, L;
map <int , map<int, int > > p ;
vector <int> vc ;
int main()
{   int mv ,u,v,w;
    while (cin >>n >>m >> L ){
        mv=0 ;
        vc.clear();
         for (int h=0; h< m ; h++){
            cin >>u >>v >>w;
           p[v][u] = w ;
           p[u][v] = w ;
           // cout << p[v][u] <<endl;
         }
         for (int h=0; h< n ; h++){
            cin >> t;
            vc.push_back(t);
            // cout << vc[h] <<endl;
         }
         if ( 0==m ) { mv= vc[0]; }
         else {
            for (int h= 2 ; h <= n ; h++){
                if ( p[1][h] >0 && p[1][h] <= L ){
                    mv= vc [h-1 ] ;
                  //  cout << h << endl;
                    L -= p[1][h];
                }
            }
         }
        cout << mv << endl;
    }

    return 0;
}

