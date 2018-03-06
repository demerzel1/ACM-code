#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int l,n;
        cin>>l>>n;
        int minn=INT_MIN,maxx=INT_MIN;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            int ta=min(a,l-a);
            int tb=max(a,l-a);
            minn=max(minn,ta);
            maxx=max(maxx,tb);
        }
        cout<<minn<<" "<<maxx<<"\n";
    }
    return 0;
}
