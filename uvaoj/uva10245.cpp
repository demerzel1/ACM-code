#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
typedef struct Point{
    double x;
    double y;
}point;

bool cmp(point a,point b){
    if(a.x<b.x)
        return true;
    return false;
}

point p[maxn];

double dist(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double solve(int l,int r){
    if(r-l==1)
        return dist(p[l],p[r]);
    if(l==r)
        return INT_MAX;
    int mid=(l+r)>>1;
    double d=min(solve(l,mid),solve(mid+1,r));
    int a=mid,b=mid;
    while(a>=l&&p[mid].x-p[a].x<d)  a--;
    while(b<=r&&p[b].x-p[mid].x<d)  b++;
    for(int i=a+1;i<b;i++){
        for(int j=i+1;j<b;j++){
            d=min(d,dist(p[i],p[j]));
        }
    }
    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n&&n){
        for(int i=0;i<n;i++){
            cin>>p[i].x>>p[i].y;
        }
        sort(p,p+n,cmp);
        double ans=solve(0,n-1);
        if(ans>10000)
            cout<<"INFINITY\n";
        else
            cout<<setiosflags(ios::fixed)<<setprecision(4)<<ans<<"\n";
    }
    return 0;
}
