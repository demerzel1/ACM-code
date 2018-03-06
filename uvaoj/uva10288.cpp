#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Fraction {
    long long num;
    long long den;
    Fraction(long long num=0,long long den=1) {
        if(den<0) {
            num=-num;
            den=-den;
        }
        assert(den!=0);
        long long g=__gcd(abs(num),den);
        this->num=num/g;
        this->den=den/g;
    }
    Fraction operator +(const Fraction &o) const {
        return Fraction(num *o.den+den*o.num,den*o.den);
    }
    Fraction operator -(const Fraction &o) const {
        return Fraction(num*o.den-den*o.num,den*o.den);
    }
    Fraction operator *(const Fraction &o) const {
        return Fraction(num*o.num,den*o.den);
    }
    Fraction operator /(const Fraction &o) const {
        return Fraction(num*o.den,den*o.num);
    }
    bool operator <(const Fraction &o) const {
        return num*o.den<den*o.num;
    }
    bool operator ==(const Fraction &o) const {
        return num*o.den==den*o.num;
    }
};

char str[20];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n) {
        memset(str,0,sizeof(str));
        //  cout<<111<<endl;
        Fraction ans=Fraction(n,1);
        for(int i=2; i<=n; i++) {
            ans=ans+Fraction(n,i);
        }
        //    cout<<222<<endl;
        // ans=Fraction(ans.num*n,ans.den);
        // printf("aaa %lld %lld\n",ans.num,ans.den);
        // cout<<ans.num<<" "<<ans.den<<"\n";
        if(ans.den==1){
            cout<<ans.num<<"\n";
        }else{
            ll a=ans.num/ans.den;
            ans.num-=ans.den*a;
            sprintf(str,"%lld",a);
            int len=strlen(str);
            for(int i=0;i<=len;i++)
                cout<<" ";
            cout<<ans.num<<"\n";
            memset(str,0,sizeof(str));
            cout<<a<<" ";
            sprintf(str,"%lld",ans.den);
            int len1=strlen(str);
            for(int i=0;i<len1;i++)
                cout<<"-";
            cout<<"\n";
            for(int i=0;i<=len;i++)
                cout<<" ";
            cout<<ans.den<<"\n";
        }
    }
    return 0;
}
