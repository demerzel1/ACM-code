#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>

using namespace std;
using ll=long long;

const int maxn = 1000005;
int n;
vector<int> v;
ll ans[maxn];
int l[maxn];
int r[maxn];

stack<int> stk;

int main () {
    cin >> n;
    int _;
    for (int i = 0; i < n; i++) {
        cin >> _;
        v.emplace_back(_);
    }
    for (int i = 0; i < n; i++) {
        while (!stk.empty()) {
            if (v[stk.top()] < v[i]){
              //  cout<<stk.top()<<endl;
                stk.pop();
            }else
                break;

        }
        if (!stk.empty())
            l[i] = i - stk.top();
        else
            l[i] = i + 1;
        stk.emplace(i);
    }
//    cout<<11<<endl;
    while (!stk.empty())
        stk.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty()) {
            if (v[stk.top()] <= v[i])
                stk.pop();
            else
                break;
        }
        if (!stk.empty())
            r[i] = stk.top() - i;
        else
            r[i] = n - i;
        stk.emplace(i);
    }
    while (!stk.empty())
        stk.pop();
    for(int i=0;i<n;i++){
       // cout<<l[i]<<' '<<r[i]<<endl;
        ans[i]=(ll)l[i]*(ll)r[i]*(ll)v[i];
    }
    for (int i = 0; i < n; i++) {
        while (!stk.empty()) {
            if (v[stk.top()] > v[i])
                stk.pop();
            else
                break;
        }
        if (!stk.empty())
            l[i] = i - stk.top();
        else
            l[i] = i + 1;
        stk.emplace(i);
    }
    while (!stk.empty())
        stk.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty()) {
            if (v[stk.top()] >= v[i])
                stk.pop();
            else
                break;
        }
        if (!stk.empty())
            r[i] = stk.top() - i;
        else
            r[i] = n - i;
        stk.emplace(i);
    }
    for(int i=0;i<n;i++){
   //     cout<<l[i]<<' '<<r[i]<<endl;
        ans[i]-=(ll)l[i]*(ll)r[i]*(ll)v[i];
    }

    ll sum=0;
    for(int i=0;i<n;i++){
      //  cout<<ans[i]<<'\n';
        sum+=ans[i];
    }
    cout<<sum<<endl;
    return 0;
}