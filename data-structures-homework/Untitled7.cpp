#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    while (cin>>s){
       int a=0;
        for(int i=0; i<(int)s.length(); i++){
            if (s[i]!='0'){
                a=i;
                break;
            }
        }
        if(a>0)
            s.erase(0,a);
        int pos=s.find('.');
        if (pos!=(int)string::npos){
            if (pos==0){
                s.erase(0,1);
                int cnt=0;
                int a=0;
                for (int i=0;i<s.length();i++){
                    if (s[i]=='0'){
                        a=i;
                        break;
                    }
                    else
                        cnt++;
                }
                if(a>0)
                    s.erase(0,a);
                if(s.length()==1){
                    cout<<s<<'E'<<0-(cnt+1)<<endl;
                }
                else{
                    s.insert(1,1,'.');
                    int b=0-(cnt+1);
                    int c=-1;
                    for(int i=s.length()-1;i>=0;i--){
                        if (s[i]!='0'){
                            c=i+1;
                            break;
                        }
                    }
                    s.erase(c);
                    if(s[s.length()-1]=='.')
                        s.erase(s.length()-1,1);
                    if(b==0)
                        cout<<s<<endl;
                    else
                        cout<<s<<'E'<<b<<endl;
                }
            }
            else if(pos==s.length()-1){
                s.erase(pos,1);
                if (s.length()==1){
                    cout<<s<<endl;
                }
                else{
                    s.insert(1,1,'.');
                    int b=s.length()-2;
                    int c=-1;
                    for (int i=s.length()-1;i>=0;i--){
                        if (s[i]!='0'){
                            c=i+1;
                            break;
                        }
                    }
                    s.erase(c);
                    if (s[s.length()-1]=='.')
                        s.erase(s.length()-1,1);
                    if (b==0)
                        cout<<s<<endl;
                    else
                        cout<<s<<'E'<<b<<endl;
                }
            }
            else{
                int a=0;
                for (int i=0;i<s.length();i++){
                    if (s[i]!='0')
                    {
                        a=i;
                        break;
                    }
                }
                if (a>0) s.erase(0,a);
                pos=s.find('.');
                s.erase(pos,1);
                s.insert(1,1,'.');
                int b=pos-1;
                int c=-1;
                for (int i=s.length()-1;i>=0;i--){
                    if (s[i]!='0'){
                        c=i+1;
                        break;
                    }
                }
                s.erase(c);
                if (s[s.length()-1]=='.')
                    s.erase(s.length()-1,1);
                if (b==0)
                    cout<<s<<endl;
                else
                    cout<<s<<'E'<<b<<endl;
            }
        }
        else{
            int a=0;
            for (int i=0;i<s.length();i++){
                if (s[i]!='0'){
                    a=i;
                    break;
                }
            }
            if (a>0) s.erase(0,a);
            if (s.length()==1){
                cout<<s<<endl;
            }
            else{
                s.insert(1,1,'.');
                int b=s.length()-2;
                int c=-1;
                for (int i=(s.length()-1);i>=0;i--){
                    if (s[i]!='0'){
                        c=i+1;
                        break;
                    }
                }
                s.erase(c);
                if (s[s.length()-1]=='.')
                        s.erase(s.length()-1,1);
                if (b==0)
                    cout<<s<<endl;
                else
                    cout<<s<<'E'<<b<<endl;
            }
        }
    }
    return 0;
}
