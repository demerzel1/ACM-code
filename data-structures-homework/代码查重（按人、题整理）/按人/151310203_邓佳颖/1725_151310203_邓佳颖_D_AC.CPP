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
        vector<long long int> fri;
        fri.clear();
        for(int i=0;i<m;i++){
            long long int t;
            scanf("%lld",&t);
            fri.push_back(t);
        }
        sort(fri.begin(),fri.end());
        long long int ans=0;
        for(int i=0;i<n;i++){
            long long int t;
            scanf("%lld",&t);
            //cout<<t<<endl;
            vector<long long int>::iterator it;
            if( (it=lower_bound(fri.begin(),fri.end(),t) )!=fri.end()){
                if(it!=fri.begin()){
                    //cout<<abs(*it-t)<<" "<<abs(*(it-1)-t)<<endl;
                   ans+=min(abs(*it-t),abs(*(it-1)-t));
                }
                else{
                    //cout<<"no"<<endl;
                   ans+=abs(*it-t);
                }
            }
            else
            {
                //cout<<"add:"<<abs(fri[ fri.size()-1 ]-t)<<endl;
                ans+=abs(fri[ fri.size()-1 ]-t);
            }
            //cout<<ans<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

