#include<bits/stdc++.h>
using namespace std;
stack<char> st;

int main() {
    char str[100005];
    scanf("%s",str);
//   printf("%d\n",strlen(str));
    if(strlen(str)%2==1) {
        printf("No");
        return 0;
    }
    int l=strlen(str);
    for(int i=0; i<l; i++) {
        if(!st.size()) {
            st.push(str[i]);
        } else {
            if(str[i]==st.top()) {
                //   printf("%c\n",str[i]);
                st.pop();
            } else {
                //    printf("push %c\n",str[i]);
                st.push(str[i]);
            }
        }

    }
    if(!st.size())
        printf("Yes");
    else
        printf("No");
    return 0;
}
