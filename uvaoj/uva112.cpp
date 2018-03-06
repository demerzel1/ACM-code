#include<bits/stdc++.h>
using namespace std;

char input(){
    char c;
    c=getchar();
    while(c==' '||c=='\n')
        c=getchar();
    return c;
}

bool solve(int val,bool* l){
    int nodeVal;
    scanf("%d",&nodeVal);
    cout<<nodeVal<<"\n";
    char c=input();
    bool ans=false,lef=false,rig=false;
    if(c=='('){
        if(solve(val-nodeVal,&lef))
            ans=true;
        c=input();
        if(solve(val-nodeVal,&rig))
            ans=true;
        c=input();
        if(lef&&rig) ans=(val==nodeVal);
    }else
        *l=true;
    return ans;
}

int main(){
    int num;
    bool leaf=false;
    while(~scanf("%d",&num)){
        input();
        if(solve(num,&leaf))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
