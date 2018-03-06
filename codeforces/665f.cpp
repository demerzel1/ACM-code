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
#include <iomanip>
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
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=200005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a) {
    return a<-eps? -1:a>eps;
}

#define MAXN 100    // pre-calc max n for phi(m, n)
#define MAXM 100010 // pre-calc max m for phi(m, n)
#define MAXP 666666 // max primes counter
#define MAX 10000010    // max prime
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
// compressed bool flag for sieve prime. (i >> 1) because even numbers are omitted.
#define setbit(ar, i) (((ar[(i) >> 6]) |= (1 << (((i) >> 1) & 31))))
#define chkbit(ar, i) (((ar[(i) >> 6]) & (1 << (((i) >> 1) & 31))))
#define isprime(x) (( (x) && ((x)&1) && (!chkbit(ar, (x)))) || ((x) == 2))

namespace pcf {
    long long dp[MAXN][MAXM];
    unsigned int ar[(MAX >> 6) + 5] = {0};
    int len = 0, primes[MAXP], counter[MAX];

    void Sieve() {
        setbit(ar, 0), setbit(ar, 1);
        for(int i = 3; (i * i) < MAX; i++, i++) {
            if(!chkbit(ar, i)) {
                int k = i << 1;
                for(int j = (i * i); j < MAX; j += k) setbit(ar, j);
            }
        }
        for(int i = 1; i < MAX; i++) {
            counter[i] = counter[i - 1];
            if(isprime(i)) primes[len++] = i, counter[i]++;
        }
    }

    void init() {
        Sieve();
        for(int n = 0; n < MAXN; n++) {
            for(int m = 0; m < MAXM; m++) {
                if(!n) dp[n][m] = m;
                else dp[n][m] = dp[n - 1][m] - dp[n - 1][m / primes[n - 1]];
            }
        }
    }

    long long phi(long long m, int n) {
        if(n == 0) return m;
        if(primes[n - 1] >= m) return 1;
        if(m < MAXM && n < MAXN) return dp[n][m];
        return phi(m, n - 1) - phi(m / primes[n - 1], n - 1);
    }

    long long Lehmer(long long m) {
        if(m < MAX) return counter[m];
        long long w, res = 0;
        int i, a, s, c, x, y;
        s = sqrt(0.9 + m), y = c = cbrt(0.9 + m);
        a = counter[y], res = phi(m, a) + a - 1;
        for(i = a; primes[i] <= s; i++) res = res - Lehmer(m / primes[i]) + Lehmer(primes[i]) - 1;
        return res;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ll n;
    pcf::init();
    cin>>n;
    ll ans=0;
    ll x,y;
    for(int i=0;i<pcf::len;i++){
        x=pcf::primes[i],y=n/x;
        if(x*x>n)
            break;
        ans+=pcf::Lehmer(y)-pcf::Lehmer(x);
    }
    for(int i=0;i<pcf::len;i++){
        x=pcf::primes[i];
        if(x*x*x>n)
            break;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
