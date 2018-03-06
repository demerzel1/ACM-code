#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <iomanip>
#include <set>
#include <climits>
#include <ctime>
#include <complex>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=100005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a){return a<-eps? -1:a>eps;}

string good;
string pat;
int n;
string s;
bool v[200];
int pos_1[maxn];
int pos_2=-1;
int cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin>>good>>pat;
    int sz=good.size();
    for(int i=0;i<sz;i++){
        v[good[i]]=true;
    }
    int len=pat.size();
    for(int i=0;i<len;i++){
        if(pat[i]=='?'){
            pos_1[cnt]=i;
            cnt++;
        }else if(pat[i]=='*')
            pos_2=i;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        int tsz=s.size();
        if(tsz==len){
            if(v[s[pos_2]]){
                cout<<"NO"<<endl;
                continue;
            }
            bool flag=true;
            for(int j=0;j<cnt;j++){
                if(!v[s[pos_1[j]]]){
                    flag=false;
                    break;
                }
            }
            if(!flag){
                cout<<"NO"<<endl;
                continue;
            }else{
                bool ff=true;
                for(int j=0;j<tsz;j++){
                    if(pat[j]!='?'&&pat[j]!='*'){
                        if(s[j]!=pat[j]){
                            cout<<"NO"<<endl;
                            ff=false;
                            break;
                        }
                    }
                }
                if(!ff){
                    continue;
                }
                cout<<"YES"<<endl;
                continue;
            }
        }else if(tsz<len){
            if(tsz!=len-1){
                cout<<"NO"<<endl;
                continue;
            }
            bool flag=true;
            for(int j=0;j<cnt;j++){
                int t=pos_1[j];
                if(t>pos_2)
                    t--;
                if(!v[s[t]]){
                    flag=false;
                    break;
                }
            }
             if(!flag){
                cout<<"NO"<<endl;
                continue;
            }else{
                bool ff=true;
                for(int j=0;j<len;j++){
                    int tp=j;
                    if(tp>=pos_2)
                        tp--;
                    if(pat[j]!='?'&&pat[j]!='*'){
                        if(s[tp]!=pat[j]){
                            cout<<"NO"<<endl;
                            ff=false;
                            break;
                        }
                    }
                }
                if(!ff){
                    continue;
                }
                cout<<"YES"<<endl;
                continue;
            }
        }else{
            if(pos_2==-1){
                cout<<"NO"<<endl;
                continue;
            }
            int tlen=tsz-len;
            bool flag=true;
            for(int j=pos_2;j<=pos_2+tlen;j++){
                if(v[s[j]]){
                    flag=false;
                    break;
                }
            }
             if(!flag){
                cout<<"NO"<<endl;
                continue;
            }
            for(int j=0;j<cnt;j++){
                int t=pos_1[j];
                if(t>pos_2)
                    t+=tlen;
                if(!v[s[t]]){
                    flag=false;
                    break;
                }
            }
            if(!flag){
                cout<<"NO"<<endl;
                continue;
            }else{
                bool ff=true;
                for(int j=0;j<len;j++){
                    int tp=j;
                    if(tp>=pos_2)
                        tp+=tlen;
                    if(pat[j]!='?'&&pat[j]!='*'){
                        if(s[tp]!=pat[j]){
                            cout<<"NO"<<endl;
                            ff=false;
                            break;
                        }
                    }
                }
                if(!ff){
                    continue;
                }
                cout<<"YES"<<endl;
                continue;
            }
        }
    }
    return 0;
}
