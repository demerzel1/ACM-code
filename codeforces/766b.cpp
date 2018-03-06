#include<bits/stdc++.h>
using namespace std;
#define maxn 100005

int a[maxn];

bool check(int i){
    if((a[i+2]<a[i]+a[i+1])&&(a[i+2]-a[i+1]<a[i]))
        return true;
    else
        return false;
}

int main() {
    bool flag=false;
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0; i<n-2; i++)
        if(check(i)) {
         //   printf("%d %d %d %d\n",i,a[i],a[i+1],a[i+2]);
            flag=true;
            break;
        }
    if(flag)
        printf("YES");
    else
        printf("NO");
    return 0;
}
