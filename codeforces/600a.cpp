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
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=1111;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-9;
inline int sgn(double a){return a<-EPS? -1:a>EPS;}

vector<string> va,vb;

bool is_num(string s){
    int sz=s.size();
    if(sz==1&&s[0]=='0')
        return true;
    if(s[0]=='0')
        return false;
    for(int i=0;i<sz;i++){
        if(s[i]<'0'||s[i]>'9')
            return false;
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    while(true){
        int sz=s.size();
        int pos=-1;
        if(sz==0){
            string t=" ";
            vb.emplace_back(t);
            break;
        }
        for(int i=0;i<sz;i++){
            if(s[i]==','||s[i]==';'){
                pos=i;
                break;
            }
        }
        if(pos==-1){
            if(is_num(s))
                va.emplace_back(s);
            else
                vb.emplace_back(s);
            break;
        }else if(pos==0){
            string t=" ";
            vb.emplace_back(t);
            s=s.substr(1);
        }else{
            string t=s.substr(0,pos);
//            cout<<"t= "<<t<<endl;
            if(is_num(t))
                va.emplace_back(t);
            else
                vb.emplace_back(t);
            s=s.substr(pos+1);
        }
    }
//    cout<<va.size()<<"\n";
//    cout<<vb.size()<<"\n";
    if(va.size()==0){
        cout<<"-\n";
    }else{
        cout<<'"';
        for(int i=0;i<va.size()-1;i++){
            cout<<va[i]<<',';
        }
        cout<<va[va.size()-1]<<'"'<<"\n";
    }
    if(vb.size()==0){
        cout<<"-\n";
    }else{
        cout<<'"';
        for(int i=0; i<vb.size()-1; i++) {
            if(vb[i]!=" ")
                cout<<vb[i]<<',';
            else
                cout<<',';
        }
        if(vb[vb.size()-1]!=" ")
            cout<<vb[vb.size()-1]<<'"'<<"\n";
        else
            cout<<'"'<<"\n";
    }

    return 0;
}
