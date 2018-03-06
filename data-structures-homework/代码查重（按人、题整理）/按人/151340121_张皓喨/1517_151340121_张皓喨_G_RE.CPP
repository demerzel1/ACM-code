#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
priority_queue <long long > p ;
priority_queue <long long > q ;
 bool vs [102] ;
int a[998];
int n, s,t,m, k, rs;
vector <int > v;
vector <int> G[102] ;
int rt  [102], lf  [102] ;
int dfs (int v){
    if (vs[v] ) return false;
    vs[v] =true;
    for ( unsigned u=0; u<G[v].size(); u++){
       int to =G[v][u] ;
       int w= rt[to];
       if ( w==-1 || dfs(w) ){
        lf[v] =to;
        rt[to] =v;
        return to ;
       }
    }
    return 0 ;
}
int main()
{


     while (cin >>n >>m){
            cin >> k ;
           /// vs.clear(); rt.clear() ; lf.clear();
            rs =0;
            memset(lf,-1,sizeof(lf) );
            memset(rt,-1,sizeof(rt) );
            for (int h=0; h< k ; h++){
                   cin >>s >>t ;
                   G[s].push_back(t+n);
                  G[t+n].push_back(s) ;
            }
         ///  t= *lower_bound(a,a+9,9);
          /// t= *lower_bound(v,v.end(),9);
          rs =0;
          for ( int h=0; h< m+n ; h++){
            memset(vs,false,sizeof(vs) );
            if ( dfs(h) ){
                rs ++;
// cout << h<< ' ' << dfs(h) <<endl;
            }
          }
          rs = (rs+ 1) / 2 ;
          cout << rs << endl;
     }

    return 0;
}

