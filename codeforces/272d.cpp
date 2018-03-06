#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define maxn 200005
struct node {
    int x;
    int y;
} num[maxn];
int m;
int cnt=0;
ll gao(int t){
    ll res=1;
    for(int i=1;i<=t;i++){
        int temp=i;
        while(temp%2==0&&cnt>0){
            temp/=2;
            cnt--;
        }
        res=(res*temp);
        if(res>m)
            res%=m;
    }
    return res;
}


bool cmp(node a,node b) {
    if(a.x==b.x)
        return a.y<b.y;
    else
        return a.x<b.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    n*=2;
    int ind=1;
    for(int i=1; i<=n; i++) {
        cin>>num[i].x;
        num[i].y=ind;
        if(ind==n/2)
            ind=0;
        ind++;
    }
    cin>>m;
    sort(num+1,num+n+1,cmp);
    ll ans=1;
    for(int i=1;i<=n;i++){
        int t=1;
        int tcnt=1;
        while(num[i].x==num[i+1].x){
            if(num[i].y==num[i+1].y)
                tcnt++;
            else{
                if(tcnt>1)
                    cnt++;
                tcnt=1;
            }
            i++;
            if(i>n)
                break;
            t++;
        }
        if(tcnt>1)
            cnt++;
        if(t>1){
            ans=ans*gao(t);
            if(ans>=m)
                ans%=m;
        }
    }
    cout<<ans<<"\n";
    return 0;
}

