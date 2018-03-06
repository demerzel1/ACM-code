#include<bits/stdc++.h>
using namespace std;
#define Maxs -947999999
int n,m,num[1010][1010];
map<int,map<int,string> > formula;
int cal(int x,int y,string &c){
    int a=0;
    for(int i=1;i<c.length();i++){
        int k=0,p=0;
        while(c[i]>='A'&&c[i]<='Z'){
            k*=26;
            k+=(c[i]-'A'+1);
            i++;
        }
        while(c[i]>='0'&&c[i]<='9'){
            p*=10;
            p+=c[i]-'0';
            i++;
        }
        if(num[p][k]==Maxs)
            a+=cal(p,k,formula[p][k]);
        else
            a+=num[p][k];
    }
    return num[x][y]=a;
}

int main(){
    int T,i,j;
    string s;
    cin>>T;
    while(T--){
        formula.clear();
        cin>>m>>n;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                cin>>s;
                istringstream sin(s);
                num[i][j]=Maxs;
                if(s[0]!='=')
                    sin>>num[i][j];
                else
                    formula[i][j]=s;
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(num[i][j]==Maxs)
                    cal(i,j,formula[i][j]);
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(j!=1)
                    cout<<" ";
                cout<<num[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
