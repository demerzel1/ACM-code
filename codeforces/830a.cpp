#include <iostream>
#include <algorithm>

using namespace std;
using ll=long long;

const int maxn = 2005;

int n, k;
ll p;
ll a[maxn];
ll b[maxn];

bool check (ll x);

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k >> p;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + k);
    ll l = 0, r = 2e9 + 1;
    while (r - l > 3) {
        ll mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
//        cout<<l<<' '<<mid<<' '<<r<<endl;
    }
    ll ans = 0;
    for (ll i = l; i <= r; i++) {
        if (check(i)) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}


bool check (ll x) {
    int ind = -1;
    for (int i = 0; i < n; i++) {
        while (ind < k) {
            ind++;
            if (abs(a[i] - b[ind]) + abs(p - b[ind]) <= x)
                break;
        }
        if (ind >= k)
            return false;
    }
    return true;
}