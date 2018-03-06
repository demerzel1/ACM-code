//下有注释
#include<bits/stdc++.h>
using namespace std;
#define Max 1000005
#define eps 1e-8
using ll=long long;
using pii=pair<int,int>;

int prime[Max];
int n,m;

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
int cnt(int n,int k)
{
    int num=0;
    while(n)
    {
        num+=n/k;
        n/=k;
    }
    return num;
}


int main(){
   // freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    IsPrime();
    int t;
    cin>>t;
    int Case=0;
    while(t--){
        cin>>m>>n;
        int ans=INT_MAX;
        for(int i=2;i<=m&&m>1;i++){
            if(prime[i]){
                int powm=0;
                while(m%i==0&&m>1){
                    m/=i;
                    powm++;
                }
                if(powm>0){
                    ans=min(ans,cnt(n,i)/powm);
                }
            }
        }
        Case++;
        cout<<"Case "<<Case<<":\n";
        if(ans>0)
            cout<<ans<<"\n";
        else
            cout<<"Impossible to divide\n";
    }
    return 0;
}



/*

n!=(k^m)*(m!)*a   其中k是该因子，m=n/k，a是不含因子k的数的乘积

下面推导这个公式

n!=n*(n-1)*(n-2)*......3*2*1

   =(k*2k*3k.....*mk)*a      a是不含因子k的数的乘积，显然m=n/k;

   =(k^m)*(1*2*3...*m)*a

   =k^m*m!*a

接下来按照相同的方法可以求出m!中含有因子k的个数。

int count(int n,int k)
{
    int num=0;
    while(n)
    {
        num+=n/k;
        n/=k;
    }
    return num;
}

*/
