#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
int S[110];
int main() {
    int n;
    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; i++) {
        scanf("%d", &S[i]);
    }
    int pre = S[1];
    int all = 0;
    if (S[1] == 0) {
        all++;
        pre = 3;
    }
    for (i = 2; i <= n; i++) {
        if (S[i] == pre && pre != 3) {
            //	cout<<"#1"<<endl;
            all++;
            pre = 3;
        } else if (pre == 3) {
            //	cout<<"#2"<<endl;
            if (S[i] == 0) {
                all++;
                pre = 3;
            } else {
                pre = S[i];
            }
        } else if (S[i] != pre) {
            //	cout<<"#3"<<endl;
            if (S[i] == 3 && pre == 1) {
                pre = 2;
            } else if (S[i] == 3 && pre == 2) {
                pre = 1;
            } else if (S[i] == 0) {
                pre = 3;
                all++;
            } else {
                pre = S[i];
            }
        }
        //	cout<<"Pre"<<pre<<endl;
    }
    printf("%d", all);
    return 0;
}
