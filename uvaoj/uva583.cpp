#include<bits/stdc++.h>
using namespace std;
#define Max 1000005
using ll=long long;
int prime[Max];
void IsPrime() {
    prime[0]=prime[1]=0;
    prime[2]=1;
    for(int i=3; i<Max; i++)
        prime[i]=i%2==0?0:1;
    int t=(int)sqrt(Max*1.0);
    for(int i=3; i<=t; i++)
        if(prime[i])
            for(int j=i*i; j<Max; j+=2*i)
                prime[j]=0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    IsPrime();
    ll n;
    while(cin>>n&&n!=0) {
        cout<<n<<" = ";
        bool f1=true;
        bool f2=true;
        if(n<0) {
            cout<<-1;
            f1=false;
            n=-n;
        }
        for(ll i=2; n!=1&&i*i<n+1; i++) {
            if(f2&&f1) {
                if(prime[i]&&n%i==0) {
                    f2=false;
                    cout<<i;
                    //    cout<<"s";
                    n/=i;
                    while(n%i==0) {
                        cout<<" x "<<i;
                        n/=i;
                    }
                }
            } else {
                if(prime[i]&&n%i==0) {
                    cout<<" x "<<i;
                    n/=i;
                    while(n%i==0) {
                        cout<<" x "<<i;
                        n/=i;
                    }
                }
            }
        }
        if((n!=1&&!f2)||(n!=1&&!f1))
            cout<<" x "<<n;
        else if(n!=1&&f2)
            cout<<n;
        cout<<"\n";
    }
    return 0;
}
