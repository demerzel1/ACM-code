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
#include <climits>
#include <ctime>
#include <complex>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 40;
int equ, var; // 有equ个方程，var个变元。增广阵行数为equ, 分别为0到equ - 1，列数为var + 1，分别为0到var.
int a[maxn][maxn];
int x[maxn]; // 解集.
bool free_x[maxn]; // 判断是否是不确定的变元.
int free_num;
void Debug(void) {
    int i, j;
    for(i = 0; i < equ; i++) {
        for(j = 0; j < var + 1; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
inline int gcd(int a, int b) {
    int t;
    while(b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
inline int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
// 高斯消元法解方程组(Gauss-Jordan elimination).(-2表示有浮点数解，但无整数解，-1表示无解，0表示唯一解，大于0表示无穷解，并返回自由变元的个数)
int Gauss(void) {
    int i, j, k;
    int max_r; // 当前这列绝对值最大的行.
    int col; // 当前处理的列.
    int ta, tb;
    int LCM;
    int temp;
    int free_x_num;
    int free_index;
    // 转换为阶梯阵.
    col = 0; // 当前处理的列.
    for(k = 0; k < equ && col < var; k++, col++) {
    //    printf("%d\n",k);
        // 枚举当前处理的行.
        // 找到该col列元素绝对值最大的那行与第k行交换.(为了在除法时减小误差)
        max_r = k;
        for(i = k + 1; i < equ; i++) {
            if(abs(a[i][col]) > abs(a[max_r][col])) max_r = i;
        }
        if(max_r != k) {
            // 与第k行交换.
            for(j = k; j < var + 1; j++) swap(a[k][j], a[max_r][j]);
        }
        if(a[k][col] == 0) {
            // 说明该col列第k行以下全是0了，则处理当前行的下一列.
            k--;
            continue;
        }
        for(i = k + 1; i < equ; i++) {
            // 枚举要删去的行.
            if(a[i][col] != 0) {
//                LCM = lcm(abs(a[i][col]), abs(a[k][col]));
//                ta = LCM / abs(a[i][col]), tb = LCM / abs(a[k][col]);
//                if(a[i][col] * a[k][col] < 0) tb = -tb;  // 异号的情况是两个数相加.
                for(j = col; j < var + 1; j++) {
//                    a[i][j] = a[i][j] * ta - a[k][j] * tb;
//                }
                a[i][j]^=a[k][j];}
            }
        }

    }
 //   Debug();
    // 1. 无解的情况: 化简的增广阵中存在(0, 0, ..., a)这样的行(a != 0).
     for (int i = var - 1; i >= 0; i--)
    {
        x[i] = a[i][var];
        for (int j = i + 1; j < var; j++)
        {
            x[i] ^= (a[i][j] && x[j]);
        }
    }
    return 0;
}
int main() {
    int T;
    scanf("%d",&T);
    equ=var=30;
    for(int cas=0;cas<T;cas++){
        memset(a,0,sizeof(a));
        memset(x,0,sizeof(x));
        memset(free_x,1,sizeof(free_x));
        for(int i=0;i<30;i++)
            scanf("%d",&a[i][30]);
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                int t=i*6+j;
                a[t][t]=1;
                if(i>0) a[(i-1)*6+j][t]=1;
                if(i<4) a[(i+1)*6+j][t]=1;
                if(j>0) a[t-1][t]=1;
                if(j<5) a[t+1][t]=1;
            }
        }
        free_num=Gauss();
        printf("PUZZLE #%d\n",cas+1);
        for(int i=0;i<30;i++){
            printf("%d",x[i]);
            if((i+1)%6==0)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}
