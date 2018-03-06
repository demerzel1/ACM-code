#include<bits/stdc++.h>
using namespace std;

int n,m,nn,mm;
int cnt1,cnt2;
bool vis[7];
int ans;
int base[50];

void dfsm(int x,int sum) {
    if(x>cnt2) {
        if(sum<mm){
            ans++;
        }
        return;
    }
    for(int i=0; i<7; i++) {
        if(!vis[i]) {
            vis[i]=true;
            dfsm(x+1,sum+i*base[x]);
            vis[i]=false;
        }
    }
    return;
}

void dfsn(int x,int sum) {
    if(x>cnt1) {
        if(sum<nn)
            dfsm(1,0);
        return;
    }
    for(int i=0; i<7; i++) {
        if(!vis[i]) {
            vis[i]=true;
            dfsn(x+1,sum+i*base[x]);
            vis[i]=false;
        }
    }
    return;
}

int main() {
    scanf("%d%d",&n,&m);
    nn=n;
    mm=m;
    if(n>1) n--;
    if(m>1) m--;
    int w=1;
    for(int i=1; i<20; i++) {
        base[i]=w;
        w*=7;
    }
    while(n) {
        n/=7;
        cnt1++;
    }
    while(m) {
        m/=7;
        cnt2++;
    }
   // printf("%d %d\n",cnt1,cnt2);
    if(cnt1+cnt2>7) {
        printf("0\n");
    } else {
        dfsn(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
