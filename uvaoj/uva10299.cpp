#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
const int maxn=50010;

int prime[maxn],primesize,phi[maxn];
bool isprime[maxn];
void getlist(int listsize) {
    memset(isprime,1,sizeof(isprime));
    isprime[1]=false;
    for(int i=2; i<=listsize; i++) {
        if(isprime[i])prime[++primesize]=i;
        for(int j=1; j<=primesize&&i*prime[j]<=listsize; j++) {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)break;
        }
    }
}
double ans;
int main() {
    //  freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    getlist(maxn);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    //  cout<<111<<"\n";
    while(cin>>n&&n) {
        if(n==1) {
            cout<<0<<"\n";
            continue;
        }
        ans=n*1.0;
        for(int i=2; i*i<=n&&n>1; i++) {
            if(isprime[i]) {
                bool flag=false;
                while(n%i==0) {
                    flag=true;
                    n/=i;
                }
                if(flag) {
                    //            cout<<i<<"\n";
                    ans*=(1.0-1.0/(i*1.0));
                }
            }
        }
        //  cout<<n<<"\n";
        if(n>1)
            ans*=(1.0-1.0/(n*1.0));
        cout<<(long long)(ans+eps)<<"\n";
    }
    return 0;
}
