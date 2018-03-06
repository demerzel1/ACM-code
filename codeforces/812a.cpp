#include<bits/stdc++.h>
using namespace std;

bool flag=false;

int mp[5][5];

int main(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cin>>mp[i][j];
    }
    if(mp[0][3]==1){
        for(int i=0;i<3;i++)
            if(mp[0][i]==1)
                flag=true;
        if(mp[3][2]==1||mp[1][0]==1||mp[2][1]==1)
            flag=true;
    }
    if(mp[1][3]==1){
        for(int i=0;i<3;i++)
            if(mp[1][i]==1)
                flag=true;
        if(mp[0][2]==1||mp[2][0]==1||mp[3][1]==1)
            flag=true;

    }
    if(mp[2][3]==1){
        for(int i=0;i<3;i++)
            if(mp[2][i]==1)
                flag=true;
        if(mp[1][2]==1||mp[3][0]==1||mp[0][1]==1)
            flag=true;
    }
    if(mp[3][3]==1){
        for(int i=0;i<3;i++)
            if(mp[3][i]==1)
                flag=true;
        if(mp[2][2]==1||mp[0][0]==1||mp[1][1]==1)
            flag=true;
    }
    if(flag==true)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
