#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int a[maxn];
int index;
bool vis[1005];
int main() {
    string s;
    cin>>s;
    int sz=s.size();
    int i=0;
    for(; i<sz; i++) {
        if(s[i]==',') {
            string str=s.substr(0,i);
            // cout<<str<<endl;
            stringstream ss;
            ss<<str;
            ss>>a[index];
            index++;
            s.erase(0,i+1);
            i=0;
            sz=s.size();
            // cout<<s<<endl;
        }
        if(s.find(',')==-1) {
            stringstream ss;
            ss<<s;
            ss>>a[index++];
            break;
        }
    }
    vector<int> v;
    for(int i=0; i<index; i++)
        v.push_back(a[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    index=v.size();
//    for(int i=0; i<index; i++) {
//        cout<<v[i]<<" ";
//    }
    if(index==1){
         cout<<v[index-1];
         return 0;
    }

    bool flag=false;
    int cnt=1;
    int fx=0;
    //  cout<<index<<"\n";
    for(int i=1; i<index; i++) {
        if(v[i]-v[i-1]==1&&i!=index-1)
            cnt++;
        else if(v[i]-v[i-1]==1&&i==index-1) {
            cnt++;
            if(!flag)
                cout<<v[fx]<<"-"<<v[i];
            else
                cout<<","<<v[fx]<<"-"<<v[i];
        } else {
            if(cnt>1) {
                if(!flag) {
                    cout<<v[fx]<<"-"<<v[i-1];
                    flag=true;
                } else
                    cout<<","<<v[fx]<<"-"<<v[i-1];
                fx=i;
                cnt=1;
            } else {
                if(!flag) {
                    cout<<v[i-1];
                    flag=true;
                } else
                    cout<<","<<v[i-1];
                fx=i;
                cnt=1;
            }
            if(i==index-1)
                cout<<","<<v[i];
        }
    }
    return 0;
}
