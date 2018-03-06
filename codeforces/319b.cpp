#include<bits/stdc++.h>
using namespace std;
#define maxn 500005

int n;
stack<int> s;
int ans[maxn];
int psy[maxn];
int mans=0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
//    cout<<n<<"\n";
    for(int i=1; i<=n; i++)
        cin>>psy[i];
    for(int i=n; i>=1; i--) {
//        cout<<222<<"\n";
        if(s.empty()) {
//            cout<<111<<"\n";
            s.push(psy[i]);
//            cout<<"psyi="<<psy[i]<<"\n";
            ans[psy[i]]=1;
            continue;
        }
        int t=s.top();
//        cout<<"t="<<t<<"\n";
        if(psy[i]>t) {
            ans[psy[i]]=max(ans[t],1);
            s.pop();
            if(!s.empty())
                t=s.top();
            while(!s.empty()&&psy[i]>t) {
                ans[psy[i]]=max(ans[psy[i]]+1,ans[t]);
                s.pop();
                if(!s.empty())
                    t=s.top();
            }
//            cout<<s.size()<<"size\n";
            s.push(psy[i]);
            mans=max(ans[psy[i]],mans);
//            cout<<mans<<"\n";
        } else
            s.push(psy[i]);
    }
    cout<<mans;
    return 0;
}
