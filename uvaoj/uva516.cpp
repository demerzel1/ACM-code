#include<bits/stdc++.h>
using namespace std;
#define Max 1000005
#define eps 1e-8
using ll=long long;
using pii=pair<int,int>;
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
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    IsPrime();
    string s;
    stringstream ss;
    while(getline(cin,s)&&s!="0") {
       // cout<<"s"<<s<<"a"<<"\n";
        int sum=1;
        ss.clear();
        ss<<s;
        // cout<<111<<"\n";
        int a,b;
        while(ss>>a) {
            ss>>b;
            //    cout<<a<<" "<<b<<"\n";
            int t=(int)(pow(a,b)+eps);
           // cout<<t<<"\n";
            sum*=t;
        }
      //    cout<<sum<<"\n";
        sum--;
        stack<pii> ans;
        int t=sqrt(sum);
        for(int i=2; i<=t+1&&sum>1; i++) {
            int p=0;
            if(prime[i])
                while(sum%i==0) {
                    p++;
                    sum/=i;
                }
         //   cout<<i<<" "<<p<<" "<<sum<<"\n";
            if(p>0)
                ans.push(make_pair(i,p));
        }
        if(sum>1)
            ans.push(make_pair(sum,1));
        while(!ans.empty()) {
            pii p=ans.top();
            cout<<p.first<<" "<<p.second;
            if(ans.size()>1)
                cout<<" ";
            ans.pop();
        }
      //  printf("111");
        cout<<"\n";
    }
    return 0;
}
