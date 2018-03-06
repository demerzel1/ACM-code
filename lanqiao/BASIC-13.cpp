#include<bits/stdc++.h>
using namespace std;
int num[205];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    sort(num,num+n);
    for(int i=0;i<n;i++){
        printf("%d ",num[i]);
    }
    return 0;
}
