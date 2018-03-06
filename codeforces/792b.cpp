#include <iostream>
#include <vector>

using ll=long long;
using namespace std;
const int maxn =200005;

vector<int> v;
int n,k;


int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        v.emplace_back(i);
    int pos=0;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        pos=(pos+x)%n;
        cout<<v[pos]<<' ';
        v.erase(v.begin()+pos);
        n--;
    }
    return 0;
}