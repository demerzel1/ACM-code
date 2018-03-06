#include<cstdio>
#include<algorithm>
#include<cstring>
#include<list>
#include<iostream>
#include<cstdlib>
#include<map>
#include<vector>
using namespace std;
#define maxn 1005
int main(){
    int n;
    int a[maxn],p[maxn];
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int cas=0;
    int cnt=0;
    int i=0;
    int d=0;
    while(true){
        if(a[i]<=cas&&p[i]==0){
            cas++;
            p[i]=1;
        }
        if(cas==n)
            break;
        if(d==0)
            i++;
        if(d==1)
            i--;
        if(i==n){
            d=1;
            cnt++;
            i--;
        }
        if(i==-1){
            d=0;
            cnt++;
            i++;
        }

    }
    printf("%d",cnt);
    return 0;
}
