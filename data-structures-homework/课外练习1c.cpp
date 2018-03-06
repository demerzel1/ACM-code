#include<cstdio>
#include<algorithm>
#include<cstring>
#include<list>
#include<iostream>
#include<cstdlib>
#include<map>
#include<vector>
using namespace std;
#define maxn 505
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main(){
    vector<int> ans;
    vector<int> num;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n*n;i++){
        int x;
        scanf("%d",&x);
        num.push_back(x);
    }
 //   cout<<"aaa"<<endl;
    sort(num.begin(),num.end());
 //   cout<<111<<endl;
    for(int i=0;i<n;i++){
        int a=num.back();
        ans.push_back(a);
    //    printf("a=%d\n",a);
        num.erase(num.end()-1);
     //   printf("%d\n",num.back());
        if(i==0)
            continue;
     //   cout<<222<<endl;
        for(int j=0;j<ans.size();j++){
         //       printf("ans.size=%d\n",ans.size());
                int cnt=0;
            for(int k=0;k<num.size();k++){
                if(cnt<2&&gcd(ans[j],a)==num[k]){
                //    printf("ans=%d a=%d k=%d num[k]=%d\n",ans[j],a,k,num[k]);
                    num.erase(num.begin()+k);
                //    printf("num[k]=%d\n",num[k]);
                    cnt++;
                }
                if(cnt==2)
                    break;
            }
        }
    }
    for(int i=0;i<n-1;i++)
        printf("%d ",ans[i]);
    printf("%d",ans[n-1]);
    return 0;
}
