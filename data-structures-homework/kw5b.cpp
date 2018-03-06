#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main() {
    mp.clear();
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        mp[a]++;
    }
    int l=mp.size();
    if(l<=2) {
        cout<<"YES";
    }
    else if(l==3) {
        map<int,int>::iterator it;
        it=mp.begin();
        int a=it->first;
        it++;
        int b=it->first;
        it++;
        int c=it->first;
 //       printf("%d %d %d\n",a,b,c);
        if(b-a==c-b)
            cout<<"YES";
        else
            cout<<"NO";
    } else
        cout<<"NO";
    return 0;
}
