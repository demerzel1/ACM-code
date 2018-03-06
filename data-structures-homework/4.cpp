#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    int cnt=0;
    int p=0;
    for(int i=0;i<str.length();i++){
        if(str[i]!='0'){
            p=i;
            break;
        }
    }
    str.erase(0,p);
    p=-1;
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]!='0'){
            p=i+1;
            break;
        }
    }
    str.erase(p);
    string::iterator it=str.begin();
    if(str[0]=='.')
        str.insert(it,'0');
    p=str.find('.');
    if(p!=string::npos){
        if(str[p-1]=='0'){
            for(int i=p;i<str.length();i++){
                if(str[i]=='0'){
                    cnt++;
                }
                else{
                    p=i;
                    break;
                }
            }
            if()
        }
    }

}
