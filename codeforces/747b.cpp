#include<bits/stdc++.h>
using namespace std;

int n;
int cnt;
int c[5];
string s;
char t[5] = {'0','A','T','C','G'};
int main() {
    cin>>n;
    cin>>s;
    for(int i=0; i<n; i++) {
        if(s[i]=='?')   cnt++;
        else if(s[i]=='A') c[1]++;
        else if(s[i]=='T') c[2]++;
        else if(s[i]=='C') c[3]++;
        else if(s[i]=='G') c[4]++;
    }
    if((n%4)!=0) {
     //   cout<<111<<endl;
        cout<<"===";
        return 0;
    }
    n/=4;
    for(int i=1; i<=4; i++) {
        if(c[i]>n) {
           // cout<<222<<endl;
            cout<<"===";
            return 0;
        }
    }
    int l=s.size();
    for(int i=0; i<l; i++) {
        if(s[i]=='?') {
            bool flag=false;
            for(int j=1; j<=4; j++) {
                if(c[j]<n) {
                    c[j]++;
                    s[i]=t[j];
                    flag=true;
                    break;
                }
            }
            if(!flag) {
             //   cout<<233<<endl;
                cout<<"===";
                return 0;
            }
            cnt--;
        }

    }
    cout<<s;
    return 0;
}
