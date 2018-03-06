#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll maxn = 105;

ll c,s;
ll x[maxn],k[maxn];
ll num[maxn][maxn];
ll tot_k=1;
int ind;
ll w[maxn];
vector<ll> ans;
ll a[maxn];
set<ll> val[maxn];

ll exgcd(ll a,ll b,ll &x,ll &y) {
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
    ll r=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return r;
}

ll CRT(ll a[], ll m[], ll n) {
    ll M = 1;
    for(int i = 0; i < n; i++) M *= m[i];
    ll ret = 0;
    for(int i = 0; i < n; i++) {
        ll x, y;
        ll tm = M / m[i];
        exgcd(tm, m[i], x, y);
        ret = (ret + tm * x * a[i]) % M;
    }
    return (ret + M) % M;
}

void dfs(int d){
    if(d==c){
        ans.push_back(CRT(a,x,c));
        return;
    }
    for(int i=0;i<k[d];i++){
        a[d]=num[d][i];
        dfs(d+1);
    }
}

void solve_crt(){
    ans.clear();
    dfs(0);
    sort(ans.begin(),ans.end());
    ll M=1;
    for(int i=0;i<c;i++)
        M*=x[i];
    for(int i=0;;i++){
        int sz=ans.size();
        for(int j=0;j<sz;j++){
            ll tans=i*M+ans[j];
            if(tans<=0)
                continue;
            cout<<tans<<"\n";
            s--;
            if(s<=0)
                return;
        }
    }
}

void solve_tot(){
    for(int i=0;i<c;i++){
        if(i==ind)
            continue;
        val[i].clear();
        for(int j=0;j<k[i];j++)
            val[i].insert(num[i][j]);
    }
    for(int t=0;;t++){
        for(int i=0;i<k[ind];i++){
            ll tans=x[ind]*t+num[ind][i];
            if(tans==0)
                continue;
            bool flag=true;
            for(int j=0;j<c;j++){
                if(j==ind)
                    continue;
                if(!val[j].count(tans%x[j])){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cout<<tans<<"\n";
                s--;
                if(s<=0)
                    return;
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>c>>s&&(c!=0&&s!=0)){
        tot_k=1;
        ind=0;
        for(int i=0;i<c;i++){
            cin>>x[i]>>k[i];
            tot_k*=k[i];
            for(int j=0;j<k[i];j++){
                cin>>num[i][j];
            }
            sort(num[i],num[i]+k[i]);
            if(k[i]*x[ind]<k[ind]*x[i])
                ind=i;
        }
        if(tot_k<10000)
            solve_crt();
        else
            solve_tot();
        cout<<"\n";
    }
    return 0;
}
