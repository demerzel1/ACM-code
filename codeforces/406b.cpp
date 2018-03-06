#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005

const int s=1000000;
bool vis[maxn];
bool vis2[maxn];
vector<int> num;
vector<int> ans;
int n;
int a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    //scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>a;
        //scanf("%d",&a);
        vis[a]=true;
        num.push_back(a);
    }
    sort(num.begin(),num.end());
    int sz=num.size();
    int index=1;
    for(int i=0;i<sz;i++){
        if(vis2[num[i]])
            continue;
        int t=s-num[i]+1;
        if(!vis[t]&&!vis2[t]){
//            cout<<"i="<<num[i]<<" t="<<t<<"\n";
            ans.push_back(t);
            vis2[num[i]]=true;
            vis2[t]=true;
        }else{
            for(int j=index;j<=s;j++){
                if(!vis[j]&&!vis[s-j+1]&&!vis2[j]&&!vis2[s-j+1]){
//                    cout<<"j="<<j<<"i="<<num[i]<<"\n";
                    vis2[j]=true;
                    vis2[s-j+1]=true;
                    vis2[num[i]]=true;
                    vis2[t]=true;
                    ans.push_back(j);
                    ans.push_back(s-j+1);
                    index=j+1;
                    break;
                }
            }
        }
    }
    sz=ans.size();
    cout<<sz<<"\n";
    for(int i=0;i<sz;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
