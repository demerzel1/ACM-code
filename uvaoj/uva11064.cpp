#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
using ll=long long;
const int maxn=200000;

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
ll ans1=1;
int main() {
    ll n;
    getlist(maxn);
    while(cin>>n) {
        ll x=n;
        ans1=1;
        ans=n*1.0;
        for(int i=2; i*i<=n&&n>1&&i<maxn; i++) {
            if(isprime[i]) {
                bool flag=false;
                int cnt=0;
                while(n%i==0) {
                    flag=true;
                    n/=i;
                    cnt++;
                }
                if(flag) {
                    //            cout<<i<<"\n";
                    ans*=(1.0-1.0/(i*1.0));
                    ans1*=(cnt+1);
                }
            }
        }
        //  cout<<n<<"\n";
        if(n>1){
            ans*=(1.0-1.0/(n*1.0));
            ans1*=2;
        }
        ll ans2=(ll)(ans+eps);
        cout<<x-ans2-ans1+1<<"\n";
    }
    return 0;
}
