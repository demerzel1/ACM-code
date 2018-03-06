#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n,t,m, L;
map <int , map<int, int > > p ;
vector <int> cn[1002] ;
vector <int> vc ; ///value
bool us [1002] ;
int mv ,u,v,w;
int dfs (  int k){
    int x = vc[1];
    int c ;
    if( us[k] ) {return 0; }
    else {
        us[k] =true;

        for (unsigned u=0; u<cn[k].size() ; u++){
             if ( p[k][u] >0 && p[k][u] <= L ){
                    c = vc [u- 0 ] ;
                  //  cout << h << endl;
                    L -= p[k][u];
                    x =  max( x , dfs (cn[k][u]) );
                }

        }
    }
    return x ;
}
int main()
{
    while (cin >>n >>m >> L ){
        mv=0 ;
        vc.clear();
         for (int h=0; h< m ; h++){
            cin >>u >>v >>w;
           p[v][u] = w ;
           p[u][v] = w ;
           cn[v].push_back(u);
                  cn[u].push_back(v) ;
           // cout << p[v][u] <<endl;
         }
         for (int h=0; h< n ; h++){
            cin >> t;
            vc.push_back(t);
            // cout << vc[h] <<endl;
         }
         if ( 0==m ) { mv= vc[0]; }
         else {

            int rs =0;
            for ( int h= 1; h<= 1 ; h++){
            memset(us,false,sizeof(us) );
            if ( true ){
                 mv=  dfs(h) ;
/// cout << h<< ' ' << dfs(h) <<endl;
            }
          }
         }
        cout << mv << endl;
    }

    return 0;
}

