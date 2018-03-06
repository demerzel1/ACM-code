#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <iterator>
#include <deque>
using namespace std;
deque <long long > a ;
deque <long long > k ;
vector <int> vc ;
vector <int> c ;
int n,t,m;
int mn ,b;
int main()
{
     while (cin >>n >>m){
           k.clear();
           a.clear()  ;
     mn =0;
            for (int h=0; h< m ; h++){
                    cin >> t;
                    a.push_back(t);
            }
            for (int h=0; h< n ; h++){
                    cin >> t;
                    k.push_back(t);
            }
            sort(k.begin(),k.end() );
            sort(a.begin(),a.end() );
            while ( !k.empty() ){
                t = a.back() ;
            // b= lower_bound(k.begin(), k.end(), t);
                k ;
            }
             cout << mn << endl;
     }

    return 0;
}

