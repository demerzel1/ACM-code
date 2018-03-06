#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


map<LL,int>b;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    while(cin>>t) {
        b.clear();
        LL tem,x,a,bit;
        char c;
        for(int i=0; i<t; i++) {
            cin>>c>>a;
            tem = a,x = 0,bit=0;
            while(tem) {
                if(tem%10%2)
                    x|=(1<<bit);
                tem/=10;
                bit++;
            }
            if(c=='+') b[x]++;
            if(c=='-') b[x]--;
            if(c=='?') cout<<b[x]<<endl;
        }
    }
    return 0;
}
