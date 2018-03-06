#include<bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int>v;
bool is_prime(int n) {
    int m=sqrt(n)+1;
    int nn=n;
    v.clear();
    for(int i=2; i<=m; ++i) {
        if(n%i==0) {
            v.push_back(i);
            while(n%i==0)
                n/= i;
        }
    }
    if(n!=1)
        v.push_back(n);
    if(v.size()==1&&v[0]==nn)
        return true;
    return false;
}

int main() {
    int n;
    cin>>n;
    if(is_prime(n)==true) {
        cout<<1;
        return 0;
    }
    if(n%2==0) {
        cout<<2;
        return 0;
    }
    if(is_prime(n-2)==true) {
        cout<<2;
    } else
        cout<<3;
    return 0;
}
