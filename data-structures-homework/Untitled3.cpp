#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int n,m;
char s[50];
int main() {
    int  k;
    char y[4];
    int d;
    int sum;
    int i;
    while(scanf("%s%d",s,&m)) {
        //	cout<<s<<ends<<m<<endl;
        k=strlen(s);
        if(k==1&&s[0]=='0'&&m==0)
            break;
        sum=0;
        if(s[0]=='0'&&k>1&&s[1]=='x') {
            sscanf(s,"%0x",&n);
        } else if(s[0]=='0'&&k>1&&s[1]!='x') {
            sscanf(s,"%o",&n);
        } else {
            sscanf(s,"%d",&n);
        }
        //	cout<<n<<endl;
        for(i=1; i<=m; i++) {
            scanf("%s%d",y,&d);
            //	cout<<d<<endl;
            if(y[0]=='i') {
                int c=strlen(y);
                if(d==n) {
                    sum++;
                }
                n=d;
                if(c>1) {
                    if(y[1]=='-') {
                        n--;
                    } else {
                        n++;
                    }
                }
            } else {
                if(y[0]=='-') {
                    if(d==n-1)
                        sum++;
                } else {
                    if(d==n+1)
                        sum++;
                }
                n=d;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
