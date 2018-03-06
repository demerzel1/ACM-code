#include <iostream>

using ll=long long;
using namespace std;

string solve_0(string a){
    int sz=a.size();
    int i;
    for(i=0; i < sz; i++){
        if(a[i]!='0')
            break;
    }
    a.erase(0,i);
    if(a.size()==0)
        a="0";
    return a;
}

string judge(string s){
    if(s.size()==0){
        s="-1";
    }
    return s;
}

int calc(string s){
    int sz=s.size();
    int res=0;
    for(int i=0;i<sz;i++) {
        res = (res + (s[i] - '0')) % 3;
    }
    return res;
}

int cnt_0(string s,int pos=1){
    int sz=s.size();
    int i;
    for(i=pos;i<sz;i++){
        if(s[i]!='0')
            break;
    }
    return i-pos;
}

string solve_1(string s){
    int t=cnt_0(s);
    int sz=s.size();
    for(int i=0;i<sz;i++){
        if((s[i]-'0')%3==1){
            if(i==0){
                if(t==0){
                    s.erase(i,1);
                    s=judge(s);
                    return s;
                }
            }else{
                s.erase(i,1);
                s=judge(s);
                return s;
            }
        }
    }
    int p[2]={-1,-1};
    int cnt=0;
    for(int i=sz;i>=0;i--){
        if((s[i]-'0')%3==2){
            p[cnt]=i;
            cnt++;
        }
        if(cnt==2)
            break;
    }
    if(cnt==2){
        if(p[1]==0){
            s.erase(p[0],1);
            s.erase(p[1],1);
            s=judge(s);
            s=solve_0(s);
            return s;
        }else{
            s.erase(p[0],1);
            s.erase(p[1],1);
            s=judge(s);
            return s;
        }
    }
    if((s[0]-'0')%3==1&&t!=0){
        s.erase(0,1);
        s=solve_0(s);
        return s;
    }
    return "-1";
}

string solve_2(string s){
    int t=cnt_0(s);
    int sz=s.size();
    for(int i=0;i<sz;i++){
        if((s[i]-'0')%3==2){
            if(i==0){
                if(t==0){
                    s.erase(i,1);
                    s=judge(s);
                    return s;
                }
            }else{
                s.erase(i,1);
                s=judge(s);
                return s;
            }
        }
    }
    int p[2]={-1,-1};
    int cnt=0;
    for(int i=sz;i>=0;i--){
        if((s[i]-'0')%3==1){
            p[cnt]=i;
            cnt++;
        }
        if(cnt==2)
            break;
    }
    if(cnt==2){
        if(p[1]==0){
            s.erase(p[0],1);
            s.erase(p[1],1);
            s=judge(s);
            s=solve_0(s);
            return s;
        }else{
            s.erase(p[0],1);
            s.erase(p[1],1);
            s=judge(s);
            return s;
        }
    }
    if((s[0]-'0')%3==2&&t!=0){
        s.erase(0,1);
        s=solve_0(s);
        return s;
    }
    return "-1";
}


int main(){
    string s;
    cin>>s;
    int res=calc(s);
    if(res==0){
        cout<<s<<endl;
    }else if(res==1){
        s=solve_1(s);
        cout<<s<<endl;
    }else if(res==2){
        s=solve_2(s);
        cout<<s<<endl;
    }
    return 0;
}