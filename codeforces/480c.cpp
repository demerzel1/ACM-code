#include <iostream>

using namespace std;
const int maxn=100005;

int pre[maxn];
int suf[maxn];

int main(){
    string a,b;
    cin>>a>>b;
    int sza=a.size();
    int szb=b.size();
    int ind=0;
    if(sza==1){
        for(int i=0;i<szb;i++){
            if(b[i]==a[0]){
                cout<<b[i]<<endl;
                return 0;
            }
        }
        cout<<'-'<<endl;
        return 0;
    }
    for(int i=0;i<sza;i++){
        if(i==0){
            if(a[i]==b[ind]){
                pre[i]=1;
                ind++;
            }
            continue;
        }
        if(ind<szb&&a[i]==b[ind]){
            pre[i]=pre[i-1]+1;
            ind++;
        }else
            pre[i]=pre[i-1];
    }
    ind=szb-1;
    for(int i=sza-1;i>=0;i--){
        if(i==sza-1){
            if(a[i]==b[ind]){
                suf[i]=1;
                ind--;
            }
            continue;
        }
        if(ind>=0&&a[i]==b[ind]){
            suf[i]=suf[i+1]+1;
            ind--;
        }else
            suf[i]=suf[i+1];
//        cout<<suf[i]<<endl;
    }
    int ans=0;
    int ansind=0;
    for(int i=0;i<sza;i++){
        if(i==0){
            ans=szb-suf[i];
//            cout<<suf[i]<<endl;
            continue;
        }
        if(i==sza-1){
            if(szb-pre[i]<ans){
                ans=szb-pre[i];
                ansind=pre[i];
            }
            continue;
        }
        if(szb-suf[i]-pre[i-1]<ans){
            ans=szb-suf[i]-pre[i-1];
            ansind=pre[i-1];
        }
    }
    if(ans<0)
        ans=0;
    b.erase(ansind,ans);
//    cout<<ansind<<' '<<ans<<endl;
    b.size() == 0 ? cout << "-\n" : cout << b << endl;
    return 0;
}