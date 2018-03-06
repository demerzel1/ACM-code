#include <bits/stdc++.h>
using namespace std;
int n, a, m;
long long sum;
int main() {
    cin>>n;
    sum = m = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        sum += a;
        m = max(m, a);
    }
    int ans=2*m-sum+1;
    cout<<ans;
    return 0;
}
