#include<cstring>
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int milk[1001];
int f(int size, int value){
    int sum = 0, count = 1;
    for (int i = 0; i < size; ++ i) {
        if(milk[i]>value){
            return size;
        }
        if(sum+milk[i]>value){
            sum=milk[i];
            count++;
        }else{
            sum+=milk[i];
        }
    }
    return count;
}

int main()
{
    int n, m;
    while (~scanf("%d%d",&n,&m)) {
        int sum = 0, max = 0;
        for (int i = 0; i < n; ++ i) {
            scanf("%d",&milk[i]);
            sum += milk[i];
            if (max < milk[i]) {
                max = milk[i];
            }
        }

        int l = max, r = sum, mid = 0;
        while (l < r) {
            mid = (l+r)/2;
            if (f(n, mid) <= m) {
                r = mid;
            }else {
                l = mid+1;
            }
        }

        printf("%d\n",l);
    }
    return 0;
}
