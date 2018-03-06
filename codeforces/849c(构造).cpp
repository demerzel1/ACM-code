#include <bits/stdc++.h>

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

template<class T>inline bool read(T&x){
    int c;
    for(c=getchar();~c&&c<33;c=getchar());
    if(!(~c)) return false;
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
    return true;
}

int k;
int sum[100005];
int ind=1;
int cnt[30];

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    for(int i=1;i<=100000;i++){
        sum[i]=sum[i-1]+i;
        if(sum[i]>100000){
            ind=i;
            break;
        }
    }
    cin>>k;
    if(k==0){
        cout<<'a';
        return 0;
    }
    int tind=0;
    while(k){
       // cout<<"k="<<k<<endl;
        int t=lower_bound(sum,sum+ind,k)-sum-1;
       // cout<<sum[t]<<' '<<t<<endl;
        if(sum[t+1]==k){
            cnt[tind]+=(t+2);
            break;
        }else{
            cnt[tind]+=(t+1);
            k-=sum[t];
        }
        tind++;
        if(k<0)
            break;
    }
    for(int i=0;i<26;++i){
        if(cnt[i]==0)
            break;
        for(int j=0;j<cnt[i];++j){
            char c='a'+i;
            cout<<c;
        }
    }
    return 0;
}