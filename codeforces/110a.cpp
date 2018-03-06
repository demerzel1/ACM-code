#include<bits/stdc++.h>
using namespace std;
int sum=0;
bool flag=false;
int main() {
    string a;
    cin>>a;
    int l=a.length();
    for(int i=0; i<l; i++)
        if(a[i]=='4'||a[i]=='7')
            sum++;
   // printf("%d",sum);
    if(sum==0) {
        flag=false;
    } else {
        while(true) {
            if(sum%10==4||sum%10==7) {
                flag=true;
                sum=sum/10;
            } else {
                flag=false;
                break;
            }
            if(sum==0) {
                break;
            }
        }
    }
    if(flag)
        printf("YES");
    else
        printf("NO");
    return 0;

}
