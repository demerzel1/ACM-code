#include<cstdio>
#include<map>
#include<iostream>
using namespace std;
map<int,int> x;
map<int,int> y;
map<pair<int,int>,int> s;
int main(){
    int n;
    int cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        cnt+=x[a]++;
        cnt+=y[b]++;
        cnt-=s[make_pair(a,b)]++;
    }
    printf("%d",cnt);
    return 0;
}
