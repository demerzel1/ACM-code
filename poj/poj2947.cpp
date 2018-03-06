#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include<iomanip>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cmath>
#include <string>
#include <cctype>
#include <cstring>
#include<complex>
#include <algorithm>
using namespace std;

char week[8][5]= {"MON","TUE","WED","THU","FRI","SAT","SUN"};
int mp[310][310];

inline int gcd(int a,int b) {
    int tp;
    while(b) {
        tp=a%b;
        a=b;
        b=tp;
    }
    return a;
}
inline int lcm(int a,int b) {
    return a*b/gcd(a,b);
}
int guass(int m,int n) {
    int row,col,i,j,k,LCM,a,b,x[305],tp;
    for(row=0,col=0; row<m&&col<n; row++,col++) {
        k=row;
        for(i=row+1; i<m; i++)
            if(abs(mp[k][col])<abs(mp[i][col]))
                k=i;
        if(k!=row) {
            for(i=col; i<=n; i++)
                swap(mp[row][i],mp[k][i]);
        }
        if(mp[row][col]==0) {
            row--;
            continue;
        }
        for(i=row+1; i<m; i++)
            if(mp[i][col]) {
                LCM=lcm(abs(mp[i][col]),abs(mp[row][col]));
                a=LCM/mp[row][col];
                b=LCM/mp[i][col];
                for(j=col; j<=n; j++)
                    mp[i][j]=(mp[i][j]*b-mp[row][j]*a)%7;
            }
    }
    for(i=row; i<m; i++)
        if(mp[i][n])
            return -1;
    if(row<n)
        return 1;
    for(i=n-1; i>=0; i--) {
        tp=mp[i][n];
        for(j=i+1; j<n; j++)
            tp-=mp[i][j]*x[j];
        while(tp%mp[i][i])
            tp+=7;
        x[i]=tp/mp[i][i];
        while(x[i]<3)
            x[i]+=7;
        while(x[i]>9)
            x[i]-=7;
    }
    for(i=0; i<n-1; i++)
        printf("%d ",x[i]);
    printf("%d\n",x[n-1]);
    return 0;
}


int main() {
    int m,n,k,a,b;
    char st[5],ch[5];
    while(scanf("%d%d",&n,&m)&&(m+n)) {
        memset(mp,0,sizeof(mp));
        for(int j=0; j<m; j++) {
            scanf("%d%s%s",&k,st,ch);
            for(int i=0; i<7; i++) {
                if(strcmp(st,week[i])==0)
                    a=i;
                if(strcmp(ch,week[i])==0)
                    b=i;
            }
            mp[j][n]=(b-a+7+1)%7;
            for(int i=0; i<k; i++) {
                scanf("%d",&a);
                mp[j][a-1]++;
                mp[j][a-1]%=7;
            }
        }
        k=guass(m,n);
        if(k==-1)
            printf("Inconsistent data.\n");
        else if(k==1)
            printf("Multiple solutions.\n");
    }
    return 0;
}
