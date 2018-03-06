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

int main(){
    int n;
    while(cin>>n){
        int x;
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>x;
            ans^=x;
        }
        if(ans==0)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
    return 0;
}
