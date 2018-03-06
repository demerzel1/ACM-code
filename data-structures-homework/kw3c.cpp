#include<bits/stdc++.h>
using namespace std;

int main(){
    double w,v,u;
    int n;
    double ans=0;
    int flagx=1,flagy=1;
    cin>>n>>w>>v>>u;
    for(int i=0;i<n;i++){
        double x,y;
        cin>>x>>y;
        if((x/v)>(y/u)){
            flagx=0;
        }
        if((x/v)<(y/u)){
            flagy=0;
        }
        ans=max(ans,x/v+(w-y)/u);
    }
    if(flagx+flagy>0)
        printf("%.10f",w/u);
    else
        printf("%.10f",ans);
    return 0;
}
