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
#include <iomanip>
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
#define endl '\n'
typedef pair<int,int> pii;
typedef long double ld;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int maxn=200005;
const int INF=0x3f3f3f3f;
const double pi=acos(-1.0);
const double eps=1e-9;
inline int sgn(double a){return a<-eps? -1:a>eps;}

int n,m;
int a[maxn];

int ch[32*maxn][2];         //节点的边信息
ll val[32*maxn];            //节点存储的值
int sz;                     //树中当前节点个数

void init(){
    memset(ch[0],0,sizeof(ch[0]));
    sz=1;
}

void _insert(ll a){//在字典树中插入 a
                  //和一般字典树的操作相同 将X的二进制插入到字典树中
    int u=0;
    for(int i=32;i>=0;i--){
        int c=((a>>i)&1);
        if(!ch[u][c]){
            memset(ch[sz],0,sizeof(ch[sz]));
            val[sz]=0;
            ch[u][c]=sz++;
        }
        u=ch[u][c];
    }
    val[u]=a;     //最后的节点插入value
}

ll query(ll a){   //在字典树中查找和a异或的值最大的元素b 返回b的值
    int u=0;
    for(int i=32;i>=0;i--){
        int c=((a>>i)&1);
        if(ch[u][c^1]) u=ch[u][c^1];//c=0,b=c^1=1,b^c=1;c=1,b=c^1=0,b^c=1;
        else u=ch[u][c];
    }
    return val[u];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        init();
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            _insert(a[i]);
        }
        int s;
        cout<<"Case #"<<cas<<":"<<endl;
        for(int i=0;i<m;i++){
            cin>>s;
            cout<<query(s)<<endl;
        }
    }
    return 0;
}
