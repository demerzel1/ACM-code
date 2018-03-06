#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    while(cin>>m>>n) {
        if(m%(n+1)==0)
            cout<<"none\n";
        else {
            if(m<=n) {
                for(int i=m; i<=n; i++){
                    if(i==m)
                        cout<<i;
                    else
                        cout<<" "<<i;
                }
            } else {
                cout<<m%(n+1);
            }
            cout<<"\n";
        }
    }
    return 0;
}
