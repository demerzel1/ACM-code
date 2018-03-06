#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
    cin>>s;
    int sz=s.length();
    if(sz==1&&s[0]>='a'&&s[0]<='z'){
        s[0]=s[0]-32;
    }else if(sz>1){
        bool flag=true;
        if(s[0]>='a'&&s[0]<='z'){
            for(int i=1;i<sz;i++){
                if(s[i]<'A'||s[i]>'Z'){
                    flag=false;
                    break;
                }
            }
        }else{
            for(int i=1;i<sz;i++){
                if(s[i]<'A'||s[i]>'Z'){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            if(s[0]>='a'&&s[0]<='z'){
                s[0]-=32;
            for(int i=1;i<sz;i++)
                s[i]+=32;
            }else{
                for(int i=0;i<sz;i++){
                    s[i]+=32;
                }
            }
        }
    }
    else if(sz==1&&s[0]>='A'&&s[0]<='Z')
        s[0]+=32;
    cout<<s<<"\n";
    return 0;
}
