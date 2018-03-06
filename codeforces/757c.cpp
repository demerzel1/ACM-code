#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
vector<int> cnt[maxn];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int num;
        scanf("%d",&num);
        for(int j=0;j<num;j++){
            int a;
            scanf("%d",&a);
            cnt[a].push_back(i);
        }
    }
    long long  ans=1;
    int t=1;
    sort(cnt+1,cnt+m+1);
    for(int i=2;i<=m;i++){
        if(cnt[i]==cnt[i-1]){
           ans=(ans*(++t))% 1000000007;
        }
        else t=1;
    }
    cout<<ans;
    return 0;
}
