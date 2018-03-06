#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <climits>
#include <ctime>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include<complex>
#include <algorithm>
using namespace std;

int factor[10005];

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n) {
        vector<int> v;
        for(int i=1; i*i<=n; i++) {
            if(n%i==0) {
                v.push_back(i);
                v.push_back(n/i);
            }
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(vector<int>::iterator it=v.begin(); it!=v.end(); it++) {
          //  cout<<*it<<"\n";
            if(*it>2){
                ans=(*it)-1;
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

