#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int pos=0;
    bool flag=true;
    for(int i=0; i<n; i++) {
        string dir;
        int d;
        cin>>d;
        cin>>dir;
        if(flag) {
            if(pos==20000) {
                if(dir!="North") {
                    flag=false;
                } else {
                    pos-=d;
                }
            } else if(pos==0) {
                if(dir!="South") {
                    flag=false;
                } else {
                    pos+=d;
                }
            } else if(pos<0||pos>20000) {
                flag=false;
            } else {
                if(dir=="North") {
                    pos-=d;
                } else if(dir=="South") {
                    pos+=d;
                }
            }
        }

    }
    if(flag&&pos==0) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }
    return 0;
}
