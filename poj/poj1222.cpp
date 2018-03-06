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
int equ, var; // ��equ�����̣�var����Ԫ������������Ϊequ, �ֱ�Ϊ0��equ - 1������Ϊvar + 1���ֱ�Ϊ0��var.
int a[maxn][maxn];
int x[maxn]; // �⼯.
bool free_x[maxn]; // �ж��Ƿ��ǲ�ȷ���ı�Ԫ.
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
// ��˹��Ԫ���ⷽ����(Gauss-Jordan elimination).(-2��ʾ�и������⣬���������⣬-1��ʾ�޽⣬0��ʾΨһ�⣬����0��ʾ����⣬���������ɱ�Ԫ�ĸ���)
int Gauss(void) {
    int i, j, k;
    int max_r; // ��ǰ���о���ֵ������.
    int col; // ��ǰ�������.
    int ta, tb;
    int LCM;
    int temp;
    int free_x_num;
    int free_index;
    // ת��Ϊ������.
    col = 0; // ��ǰ�������.
    for(k = 0; k < equ && col < var; k++, col++) {
    //    printf("%d\n",k);
        // ö�ٵ�ǰ�������.
        // �ҵ���col��Ԫ�ؾ���ֵ�����������k�н���.(Ϊ���ڳ���ʱ��С���)
        max_r = k;
        for(i = k + 1; i < equ; i++) {
            if(abs(a[i][col]) > abs(a[max_r][col])) max_r = i;
        }
        if(max_r != k) {
            // ���k�н���.
            for(j = k; j < var + 1; j++) swap(a[k][j], a[max_r][j]);
        }
        if(a[k][col] == 0) {
            // ˵����col�е�k������ȫ��0�ˣ�����ǰ�е���һ��.
            k--;
            continue;
        }
        for(i = k + 1; i < equ; i++) {
            // ö��Ҫɾȥ����.
            if(a[i][col] != 0) {
//                LCM = lcm(abs(a[i][col]), abs(a[k][col]));
//                ta = LCM / abs(a[i][col]), tb = LCM / abs(a[k][col]);
//                if(a[i][col] * a[k][col] < 0) tb = -tb;  // ��ŵ���������������.
                for(j = col; j < var + 1; j++) {
//                    a[i][j] = a[i][j] * ta - a[k][j] * tb;
//                }
                a[i][j]^=a[k][j];}
            }
        }

    }
 //   Debug();
    // 1. �޽�����: ������������д���(0, 0, ..., a)��������(a != 0).
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
