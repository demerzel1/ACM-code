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
typedef pair<int,int> pii;
typedef long long ll;

int gcd(int a,int b){
    if(!a)return 1;if(!b)return a;
    if(a<0) a=-a; for(int t;b;t=a%b,a=b,b=t);
    return a;
}


int main(){
    int x1,y1,x2,y2;
    int x,y;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    scanf("%d%d",&x,&y);
    int t1=abs(x2-x1);
    int t2=abs(y2-y1);
    int t3=t1/x;
    int t4=t2/y;
    int t5=abs(t3-t4);
    if((t1%x==0)&&(t2%y==0)&&t5%2==0)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
