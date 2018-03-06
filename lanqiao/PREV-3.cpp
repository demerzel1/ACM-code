#include<bits/stdc++.h>
using namespace std;

int n;
bool vis[20];
string str[10]={"0","1","2","3","4","5","6","7","8","9"};
int ans;
map<int,int> mp;
void dfs(string s,int d){
    if(d==9){
        for(int i=1;i<=7;i++){
            string t=s.substr(0,i);
            int a=atoi(t.c_str());
            if(a>n)
                break;
            for(int j=i+(9-i)/2)
        }
        return;
    }
    for(int i=1;i<=9;i++){
        if(!vis[i]){
            vis[i]=true;
            dfs(s+str[i],d+1);
            vis[i]=false;
        }
    }
    return;
}

int main(){
    cin>>n;
    dfs("",0);
    cout<<ans;
    return 0;
}
