#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=100005;
#define endl '\n'
int n,l,x,y;
int a[maxn];
int ans;
bool flag1,flag2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>l>>x>>y;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(flag1&&flag2)
            break;
        int p=lower_bound(a+i,a+n,a[i]+x)-a;
        int p1=lower_bound(a+i,a+n,a[i]+y)-a;
        if(p==n&&p1==n)
            break;
        if(p!=n&&!flag1){
            if(a[p]==a[i]+x){
                flag1=true;
            }
        }
        if(p1!=n&&!flag2){
            if(a[p1]==a[i]+y)
                flag2=true;
        }
    }
    if(flag1&&flag2){
        cout<<0<<endl;
        return 0;
    }
    if(flag1&&!flag2){
        cout<<1<<endl;
        cout<<y<<endl;
        return 0;
    }
    if(!flag1&&flag2){
        cout<<1<<endl;
        cout<<x<<endl;
        return 0;
    }
    bool flag=false;
    for(int i=0;i<n;i++){
        int p=lower_bound(a+i,a+n,a[i]+x)-a;
        int p1=lower_bound(a+i,a+n,a[i]+y)-a;
        if(p!=n){
            int t1=a[i]+x;
            int t2=a[p]-t1;
            if(t2==y){
                flag=true;
                ans=t1;
                break;
            }
            int p3=lower_bound(a,a+n,t1-y)-a;
            if(p3>=0){
                if(t1-y==a[p3]){
                    flag=true;
                    ans=t1;
                    break;
                }
            }
        }
        if(p1!=n){
            int t1=a[i]+y;
            int t2=a[p1]-t1;
            if(t2==x){
                flag=true;
                ans=t1;
                break;
            }
            int p3=lower_bound(a,a+n,t1-x)-a;
            if(p3>=0){
                if(t1-x==a[p3]){
                    flag=true;
                    ans=t1;
                    break;
                }
            }
        }
        if(a[i]-x>=0){
            int p2=lower_bound(a,a+n,a[i]-x+y)-a;
            if(p2!=n){
                if(a[p2]-y==a[i]-x){
                    flag=true;
                    ans=a[i]-x;
                    break;
                }
            }
        }
        if(a[i]-y>=0){
            int p2=lower_bound(a,a+n,a[i]-y+x)-a;
            if(p2!=n){
                if(a[p2]-x==a[i]-y){
                    flag=true;
                    ans=a[i]-y;
                    break;
                }
            }
        }
    }
    if(flag){
        cout<<1<<endl;
        cout<<ans<<endl;
        return 0;
    }
    cout<<2<<endl<<x<<' '<<y<<endl;
    return 0;
}