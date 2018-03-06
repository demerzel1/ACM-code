//Code here
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        vector<int> fri;
        for(int i=0;i<m;i++){
            int t;
            scanf("%d",&t);
            fri.push_back(t);
        }
        sort(fri.begin(),fri.end());
        long long int ans=0;
        for(int i=0;i<n;i++){
            int t;
            scanf("%d",&t);
            vector<int>::iterator it;
            if( (it=lower_bound(fri.begin(),fri.end(),t) )!=fri.end()){
                if(it!=fri.end()-1){
                    ans+=abs(*it-t);
                }
                else{
                   ans+=min(abs(*it-t),abs(*(it+1)-t));
                }
            }
            else
            {
                //cout<<"add:"<<abs(fri[ fri.size()-1 ]-t)<<endl;
                ans+=abs(fri[ fri.size()-1 ]-t);
            }
        }
        cout << ans << endl;
    }

    return 0;
}

