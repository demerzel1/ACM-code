//4

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1000005;

vector<int> friend_level;
vector<int> self_level;
vector<bool> matched;
vector<int> big;
vector<int> small;

int main()
{
    int n,m;
    while(cin>>n>>m){
        friend_level.resize(m);
        for(int i=0;i<m;i++){
            cin>>friend_level[i];
        }
        self_level.resize(n);
        for(int i=0;i<n;i++){
            cin>>self_level[i];
        }
        sort(friend_level.begin(),friend_level.end());
        sort(self_level.begin(),self_level.end());

        if(friend_level.size()>self_level.size()){
            big = friend_level;
            small = self_level;
        }
        else{
            big = self_level;
            small = friend_level;
        }

        matched.resize(big.size());
        fill(matched.begin(),matched.end(),false);

        long long sum=0;
        int small_index=0;
        for(int i=0;i<big.size();i++){
            if(small_index==small.size()){
                break;
            }

            int sub_front = abs(big[i]-small[small_index]);
            int sub_next = abs(big[i+1]-small[small_index]);
            if(sub_front<=sub_next){
                matched[i] = true;
                sum += sub_front;
                small_index++;
            }
        }
        if(small_index<small.size()){
            for(int i=big.size()-1;i>=0;i--){
                if(small_index==small.size()){
                    break;
                }

                if(!matched[i]){
                    matched[i] = true;
                    sum += abs(big[i]-small[small_index]);
                    small_index++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

