#include<bits/stdc++.h>
using namespace std;
#define eps 1e-6
struct node{
    double j;
    double f;
    double p;
    node(double a=0,double b=0){
        j=a;
        f=b;
        p=b/a;
    }
};
bool cmp(const node a,const node b){
    if(a.p<b.p)
        return true;
    else
        return false;
}
vector<node> v;
int main(){
    int n;
    int m;
    while(cin>>m>>n){
        if(m==-1&&n==-1)
            break;
        v.clear();
        double a,b;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            v.push_back(node(a,b));
        }
        sort(v.begin(),v.end(),cmp);
        double ans=0;
        for(int i=0;i<v.size();i++){
           // cout<<v[i].f<<" "<<v[i].j<<" "<<v[i].p<<"\n";
            if(m>=v[i].f){
                m-=v[i].f;
                ans+=v[i].j;
            }else{
             //   cout<<11<<"\n";
                //ans+=(m/v[i].f)*v[i].j;
                ans+=m/v[i].p;
                m=0;
                break;
            }
        }
        printf("%.3f\n",ans);
     //   cout<<fixed<<setprecision(3)<<ans<<"\n";
    }
    return 0;
}
