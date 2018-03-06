#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int a[maxn];
int main() {
    int n,m;
    int cnt=0;
    int sum=0;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0; i<n; i++) {
        if(a[i]<0&&cnt<m) {
            sum+=(-a[i]);
            cnt++;
        } else
            break;
    }
    printf("%d",sum);
    return 0;
}
