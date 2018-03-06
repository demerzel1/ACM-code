#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,l;
#define maxn 100005
int a[maxn];
int k[maxn];

int main() {
    while(scanf("%d",&n)!=EOF) {
        memset(a,0,sizeof(a));
        memset(k,0,sizeof(k));
        scanf("%d",&m);
        for(int i=0; i<m; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&k[i]);
        sort(a,a+m);
        sort(k,k+n);
        LL sum=0;
        for(int i=0; i<n; i++) {
            int x=1000000;
            for(int j=0; j<m; j++) {
                // cout<<abs(k[i]-a[j])<<endl;
                if(x>abs(k[i]-a[j])) {
                    //         printf("i=%d j=%d x=%d\n",i,j,abs(k[i]-a[j]));
                    x=abs(k[i]-a[j]);
                }
                else if(j!=0&&a[j]!=a[j-1])
                    break;
            }
            sum+=x;
            //     cout<<sum<<endl;
        }
        cout<<sum<<endl;
        //  cout<<111<<endl;
        //   cout<<n<<" "<<m<<endl;
    }
    return 0;
}



