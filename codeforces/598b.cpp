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

char old[10005];
char ans[10005];
int index[10005];
int m;
int l,r,k;
int main(){
    cin>>old;
    cin>>m;
    int sz=strlen(old);
    while(m--){
        cin>>l>>r>>k;
        l--;
        r--;
        for(int i=0;i<sz;i++){
            index[i]=i;
        }
        k=k%(r-l+1);
        for(int i=l;i<=r;i++){
            int t=i-l+k;
            t=t%(r-l+1);
            index[t+l]=i;
        }
//        for(int i=0;i<sz;i++){
//            cout<<index[i]<<" ";
//        }
//        cout<<"\n";
        for(int i=0;i<sz;i++){
            ans[i]=old[index[i]];
        }
        ans[sz]='\0';
        strcpy(old,ans);
//        cout<<old<<"\n";
    }
    cout<<ans<<"\n";
    return 0;
}
