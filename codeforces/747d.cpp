#include<bits/stdc++.h>
using namespace std;
#define maxn 200005

int t[maxn];
priority_queue<int, vector<int>, greater<int> >cnt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int c0=0;
    int c1=0;
    bool flag=false;
    int j=0;
    for(int i=0; i<n; i++) {
        cin>>t[i];
        if(!flag) {
            if(t[i]<0) {
                flag=true;
                c0++;
            }
        } else {
            if(t[i]<0) {
                c0++;
                if(c1!=0) {
                    cnt.push(c1);
                    c1=0;
                }
            } else {
                c1++;
            }
        }
    }
    if(k<c0){
        cout<<"-1";
        return 0;
    }
    if(n==c0){
        cout<<"1";
        return 0;
    }
    int num=0;
  //  cout<<"C1="<<c1<<"\n";
    if(c1) {
        num=c1;
        cnt.push(c1);
        c1=0;
    }
  //  cout<<"C0="<<c0<<"\n";
    int last=k-c0;
    int ans;
        ans=cnt.size()*2-1;
    }
 //   cout<<ans<<"ans\n";
    while(last>0&&cnt.size()>0) {
        int a=cnt.top();
     //   cout<<a<<"a\n";
        if(a!=num&&last>=a) {
            last-=a;
            cnt.pop();
            ans-=2;
        } else if(a==num&&last>=a) {

       //     cout<<cnt.size()<<"size\n";
            if(cnt.size()==1) {
                last-=a; cnt.pop();
                ans-=1;
            } else {
                cnt.pop();
                int b=cnt.top();
          //      cout<<b<<"b\n";
                if(b!=a) {
             //       cout<<11<<"\n";
                    last-=a;
                    ans-=1;
                } else {
            //        cout<<22<<"\n";
                    last-=a;
                    ans-=2;
                }
            }
        } else if(last<a) {
            break;
        }
    }


    cout<<ans;
    return 0;
}
