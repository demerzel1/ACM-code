#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
int main(){
    string a,b;
    char c;
    mp.clear();
    while((c=getchar())!='\n'){
        ungetc(c,stdin);
        cin>>a>>b;
        mp[b]=a;
        getchar();
    }
    string s;
    while(cin>>s){
        if(mp.find(s)!=mp.end())
            cout<<mp[s]<<endl;
        else
            cout<<"eh"<<endl;
    }
    return 0;
}
