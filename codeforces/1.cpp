#include<bits/stdc++.h>
#define maxn 100010
using namespace std;
using ll=long long;
int phi[maxn];
bool prime[maxn];
struct node{
    int num[50];
    int cnt;
}n[maxn];
vector<int> pri;
void getphi() {
    phi[1]=1;
    for(int i=2; i<maxn; i++){
         phi[i]=i;
    }
    for(int i=2; i<maxn; i++){
        if(i==phi[i]){
            prime[i]=true;
            pri.push_back(i);
            for(int j=i; j<maxn; j+=i){
                 phi[j]=phi[j]/i*(i-1);
                 n[j].num[n[j].cnt]=i;
                 n[j].cnt++;
            }
        }
    }
}

int a,b,c,d,k;
ll sumphi[maxn];
void init(){
    sumphi[1]=1;
    for(int i=2;i<maxn;i++){
        sumphi[i]=sumphi[i-1]+phi[i];
    }
}

ll rongchi(int ind,int b,int m){
    ll tans=0;
    ll t;
    for(int i=ind;i<n[m].cnt;i++){
        t=b/n[m].num[i];
        tans+=t-rongchi(i+1,t,m);
    }
    return tans;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    getphi();
    init();
    int t;
    int Case=0;
    scanf("%d",&t);
    while(t--) {
        ll ans=0;
        Case++;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k==0){
            printf("Case %d: 0\n",Case);
            continue;
        }
        b=b/k;
        d=d/k;
        if(b>d)
            swap(b,d);
        ans=sumphi[b];
        for(int i=b+1;i<=d;i++){
            ans+=b-rongchi(0,b,i);
        }
        printf("Case %d: %lld\n",Case,ans);
    }
    return 0;
}
