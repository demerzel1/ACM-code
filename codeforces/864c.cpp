#include<iostream>

using namespace std;

int main(){
    int a,b,f,k;
    cin>>a>>b>>f>>k;
    int res=b;
    int ff=f;
    int ans=0;
    for(int i=0;i<k-1;++i){
        if(res>=2*a-ff){
            res-=a;
        }else if(res>=ff){
            ans++;
            res=b-(a-ff);
        }else{
            cout<<"-1\n";
            return 0;
        }
        ff=a-ff;
    }
    if(res>=a){
        cout<<ans<<endl;
    }else if(res>=ff&&b>=a-ff){
        cout<<ans+1<<endl;
    }else
        cout<<"-1"<<endl;
    return 0;
}