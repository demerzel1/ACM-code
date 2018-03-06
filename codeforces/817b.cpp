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
#include <complex>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;


ll num[100005];
ll ans;


int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        cin>>num[i];
    sort(num,num+n);
    if(num[0]==num[1]==num[2]) {
        ll cnt=0;
        for(int i=0; i<n; i++) {
            if(num[i]==num[0])
                cnt++;
            else
                break;
        }
        ans=(cnt*(cnt-1)*(cnt-2))/(ll)6;
        cout<<ans<<"\n";
        return 0;
    }
    if(num[0]==num[1]) {
        ll cnt=0;
        for(int i=2; i<n; i++) {
            if(num[i]==num[2])
                cnt++;
            else
                break;
        }
        ans=cnt;
        cout<<ans<<"\n";
        return 0;
    }
    if(num[1]==num[2]) {
        ll cnt=0;
        for(int i=1; i<n; i++) {
            if(num[i]==num[1])
                cnt++;
            else
                break;
        }
        ans=(cnt*(cnt-1))/(ll)2;
        cout<<ans<<"\n";
        return 0;
    }
    ll cnt=0;
    for(int i=2; i<n; i++) {
        if(num[i]==num[2])
            cnt++;
        else
            break;
    }
    ans=cnt;
    cout<<ans<<"\n";
    return 0;
}
