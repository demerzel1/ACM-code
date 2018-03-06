//8

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1005;

void getFail(string P,int* f)
{
    int m = P.size();
    f[0] = 0;
    f[1] = 1;
    for(int i=1;i<m;i++){
        int j = f[i];
        while(j&&P[i]!=P[j])
            j = f[j];
        f[i+1] = P[i]==P[j]?j+1:0;
    }
}

vector<int> ans;
void find(string T,string P,int* f)
{
    int n = T.size(),m = P.size();
    getFail(P,f);
    int j=0;
    for(int i=0;i<n;i++){
        while(j&&P[j]!=T[i])
            j = f[j];
        if(P[j]==T[i])
            j++;
        if(j==m){
            ans.push_back(i-m+1);
            return;
        }
    }
}

string str;
string key;
int f[MAX];

int main()
{
    int L;
    while(cin>>L){
        getchar();
        getline(cin,str);
        cin>>L;
        getchar();
        getline(cin,key);
        memset(f,0,sizeof(f));
        find(str,key,f);
        
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            if(i)
                cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}



