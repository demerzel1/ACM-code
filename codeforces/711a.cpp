#include<bits/stdc++.h>
using namespace std;
int n;
char s[1005][10];
bool flag;
int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%s",s[i]);
        if(!flag) {
            if(s[i][0]=='O') {
                if(s[i][1]=='O') {
                    flag=true;
                    s[i][0]='+';
                    s[i][1]='+';
                }
            }
            if(!flag&&s[i][3]=='O') {
                if(s[i][4]=='O') {
                    flag=true;
                    s[i][3]='+';
                    s[i][4]='+';
                }
            }
        }
    }
    if(flag) {
        printf("YES\n");
        for(int i=0; i<n; i++) {
            printf("%s\n",s[i]);
        }
    }

    else
        printf("NO\n");
    return 0;
}
