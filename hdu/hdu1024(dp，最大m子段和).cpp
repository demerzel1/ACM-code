#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=1000005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;

template<class T>inline bool read(T&x){
    int c;
    for(c=getchar();~c&&c<33;c=getchar());
    if(!(~c)) return false;
    for(x=0;c>32;x=x*10+c-'0',c=getchar());
    return true;
}

int dp[maxn];
int n,m;
int a[maxn];

int main () {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    while(cin>>m>>n) {
        for (int i = 1; i <= n; i++){
            cin>>a[i];
            dp[i]=0;
        }
        for(int i=1;i<=m;i++){
            int t=0;
            for(int j=1;j<=i;j++)
                t+=a[j];
            dp[n]=t;
            for(int j=i+1;j<=n;j++){
                t=max(t,dp[j-1])+a[j];
                dp[j-1]=dp[n];
                dp[n]=max(dp[n],t);
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}

/*

【问题描述】----最大M子段和问题
给定由 n个整数（可能为负整数）组成的序列a1，a2，a3，……，an，以及一个正整数 m，要求确定序列 a1，a2，a3，……，an的 m个不相交子段，
使这m个子段的总和达到最大，求出最大和。

题解：转自http://www.cnblogs.com/peng-come-on/archive/2012/01/15/2322715.html
动态规划的思想。
1.基本思路：
  首先，定义数组num[n],dp[m][n].
  num[n]用来存储n个整数组成的序列.
  dp[i][j]用来表示由前 j项得到的含i个字段的最大值，且最后一个字段以num[j]项结尾。仔细想想，我们可以知道：
  dp[i][j]=max(dp[i][j-1]+num[j],dp(i-1,t)+num[j])   其中i-1<=t<=j-1.
  (因为必须是以 num[j] 结尾的，所以num[j]一定属于最后一个子段，即要么自己独立成一个子段，要么与前边以num[j-1]结尾的子段联合)
  所求的最后结果为 max( dp[m][j] ) 其中1<=j<=n.
  但是，我们会发现，当n非常大时，这个算法的时间复杂度和空间复杂度是非常高的,时间复杂度近似为O(m*n^2),
  空间复杂度近似为O(m*n).因此，我们需要优化算法来降低时间复杂度和空间复杂度.
2.优化算法：
  (1)节省时间
  由基本思路，我们可以知道，dp[i][j]=max(dp[i][j-1]+num[j],dp(i-1,t)+num[j])，其中i-1<=t<=j-1.我们只要找到dp[i][j-1]
  和dp[i-1][t]的最大值加上num[j]即为dp[i][j].所以，定义一个数组pre_max[n]，用pre_max[j-1]来表示求解dp[i][j]时dp[i-1][t]
  的最大值,则dp[i][j]=max(pre_max[j-1],dp[i][j-1])+num[j].
  特别注意，pre_max[n]这个位置的存储空间是始终用不到的，因此可以用来存储其他数值，在接下来会用到。
  在求解dp[i][j]的同时，我们可以计算出dp[i][t];i<=t<=j的最大值，这个最大值在计算dp[i+1][j+1]的时候需要作为pre_max[j]的
  形式被使用，我们先把它存在pre_max[n]中。
  你可能会问：为什么不把它直接放在pre_max[j]中呢？因为你接下来需要计算dp[i][j+1]的值，需要用到pre_max[j]中原来的值，
  如果你把它存在这里，就会覆盖掉计算dp[i][j+1]所需要的那个值。所以，先把它放在pre_max[n]中。
  当我们计算完dp[i][j+1]之后，就会发现pre_max[j]中的值已经没有用处了，我们可以把它更新为计算dp[i+1][j+1]所需要的那个值，
  即之前放在pre_max[n]中的那个值，即执行pre_max[j]=pre_max[n].
  这样我们就节省了计算最大值时付出的时间代价。
  (2)节省空间
  通过时间的节省，我们突然间发现程序执行结束后pre_max[n]的值即为最后的结果，pre_max[n]数组才是我们希望求解的，
  dp[m][n]这个庞大的数组已经不是那么重要了，因此，我们现在用整型数tmp来代替dp[m][n]，用来临时存储dp[i][j]的值，
  作为求解pre_max[n]的中介。
  这样就节省了dp[i][j]占用的极大的空间.


 */