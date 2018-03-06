#include<bits/stdc++.h>
using namespace std;
#define maxn 1005

int k,n;
bool G[maxn][maxn];

void add(int i,int j) {
    G[i][j]=true;
    G[j][i]=true;
}

void pre() {
    add(1,3);
    add(1,4);
    add(1,5);
    for(int i=1; i<n; i++) {
        add(i*3,(i+1)*3);
        add(i*3+1,(i+1)*3+1);
        add(i*3+1,(i+1)*3+2);
        add(i*3+2,(i+1)*3+1);
        add(i*3+2,(i+1)*3+2);
    }
    add(n*3,2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>k;
    k--;
    int t=k;
    while(t>0) {
        n++;
        t/=2;
    }
//    cout<<n<<"\n";
    if(k==0) {
        cout<<2<<"\n";
        cout<<"NY\nYN\n";
        return 0;
    }
    pre();
    int cnt=0;
    while(k>0) {
        cnt++;
        if(k%2==1) {
            if(cnt==n)
                add(n*3+1,2);
            else
                add(3*cnt+1,(cnt+1)*3);
        }
        k/=2;
    }
    cout<<n*3+2<<"\n";
    for(int i=1; i<=n*3+2; i++) {
        for(int j=1; j<=n*3+2; j++) {
            if(G[i][j])
                cout<<"Y";
            else
                cout<<"N";
        }
        cout<<"\n";
    }
    return 0;
}
