#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
int num[10005];
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        sum+=num[i];
    }
    sort(num,num+n);
    printf("%d\n%d\n%d\n",num[n-1],num[0],sum);
    return 0;
}


