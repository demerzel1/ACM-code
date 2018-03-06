#include <iostream>
#include <map>
#include <vector>
#include <string.h>
using namespace std;
int n,t,m, L;
map <int , map<int, int > > p ;
vector <int> cn[1002] ;
vector <int> vc ; ///value
bool us [1002] ;
int mv ,u,v,w;
int dfs (  int k){
    int c =1;
    if( us[k] ) {return 0; }
    else {
        us[k] =true;

        for (unsigned u=0; u<cn[k].size() ; u++){
             if ( p[k][u] >0 && p[k][u] <= L ){
                    mv = vc [u-1 ] ;
                  //  cout << h << endl;
                    L -= p[k][u];
                }
           c += dfs (cn[k][u]);
        }
    }
    return mv ;
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
            for (int h= 2 ; h <= n ; h++){
                if ( p[1][h] >0 && p[1][h] <= L ){
                    mv= vc [h-1 ] ;
                  //  cout << h << endl;
                    L -= p[1][h];
                }
            }
            int rs =0;
            for ( int h= 1; h<= n ; h++){
            memset(us,false,sizeof(us) );
            if ( dfs(h) ){
                rs ++;
/// cout << h<< ' ' << dfs(h) <<endl;
            }
          }
         }
        cout << mv << endl;
    }

    return 0;
}

