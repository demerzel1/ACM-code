#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <ctime>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
int occur[30],low[25000],high[25000],pre[25000];
int a[25000],b[100000];
int ans[100000];

bool Cmp(int *a,int *b,int k){
    if(b[occur[a[k]]]!=b[k])
        return false;
    if((low[k]>=0)&&b[low[k]]>=b[k])
        return false;
    if((high[k]>=0)&&b[high[k]]<=b[k])
        return false;
    return true;
}

int main(){
    int n,k,s;
    int i,j,m;
    scanf("%d%d%d",&n,&k,&s);
    for(i=0;i<n;i++)
        scanf("%d",b+i);
    for(i=1;i<=s;i++)
        occur[i]=-1;
    occur[0]=occur[s+1]=-2;
    for(i=0;i<k;i++){
        scanf("%d",a+i);
        if(occur[a[i]]==-1)
            occur[a[i]]=i;
        for(j=a[i]-1;occur[j]==-1;j--);
        low[i]=occur[j];
        for(j=a[i]+1;occur[j]==-1;j++);
        high[i]=occur[j];
    }
    pre[0]=-1;
    j=-1;
    for(i=1;i<k;i++){
        while(j>=0&&!Cmp(a,a+(i-j-1),j+1))
            j=pre[j];
        if(Cmp(a,a+(i-j-1),j+1))
            j++;
        pre[i]=j;
    }
    j=-1;
    m=0;
    for(i=0;i<n;i++){
        while(j>=0&&!Cmp(a,b+(i-j-1),j+1))
            j=pre[j];
        if(Cmp(a,b+(i-j-1),j+1)) j++;
        if(j+1==k){
            ans[m++]=i-j+1;
            j=pre[j];
        }
    }
    printf("%d\n",m);
    for(i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
