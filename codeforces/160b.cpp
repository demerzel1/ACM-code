#include<bits/stdc++.h>
using namespace std;
#define maxn 105

int a1[maxn];
int a2[maxn];
int n;
bool f1=true;
bool f2=true;

int main(){
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
        a1[i]=s[i]-'0';
    for(int i=n;i<2*n;i++)
        a2[i-n]=s[i]-'0';
    sort(a1,a1+n);
    sort(a2,a2+n);
    for(int i=0;i<n;i++){
        if(a1[i]<=a2[i]){
            f1=false;
        }
        if(a1[i]>=a2[i]){
            f2=false;
        }
        if(f1!=true&&f2!=true)
            break;
    }
    if(f1||f2)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
