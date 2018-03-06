#include<bits/stdc++.h>
using namespace std;
#define Max 5005
#define eps 1e-8
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
int sz;
int prime[Max];
int n,m;
vector<int> pri;

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
    for(int i=2;i<5000;i++)
        if(prime[i])
            pri.push_back(i);
    sz=pri.size();
}

map<ull,ull> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    IsPrime();
    int T;
    cin>>T;
    int Case=0;
    while(T--){
        mp.clear();
        Case++;
        int n;
        char s[50];
        cin>>n>>s;
        int k=strlen(s);
        for(int i=n;i>0;i-=k){
            int t=i;
            for(int j=0;pri[j]*pri[j]<=t&&j<sz;j++){
                if(t%pri[j]==0){
                    while(t%pri[j]==0){
                        t/=pri[j];
                        mp[pri[j]]++;
                    }
                }
            }
            if(t>1)
                mp[t]++;
        }
        ull ans=1;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans*=(it->second+1);
            if(ans>1e18)
                break;
        }
        cout<<"Case "<<Case<<": ";
        if(ans>1e18)
            cout<<"Infinity\n";
        else
            cout<<ans<<"\n";
    }
    return 0;
}


/*
如果
n = p1^a1*p2^a2...pk^ak;
那么因子个数为
(a1+1)*(a2+1)*...*(ak+1)

以{2,2,3,3,5}为例,2个2\2个3\1个5

{1,2,4}
{1,3,9}
{1,5}
从每个集合里面选1个
所以总共(2+1)(2+1)(1+1)=18个
*/
