//1

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 10000;

int main()
{
    int n,m;
    vector<int> num;
    while(cin>>n>>m){
        num.resize(n);
        long long sum=m;
        int sign=-12,cnt=0;
        for(int i=0;i<n;i++){
            cin>>num[i];
            if(num[i]!=0)
                sum *= num[i];
            if(num[i]<0){
                cnt++;
                if(num[i]>sign){
                    sign = num[i];
                }
            }
        }

        if(cnt&1){
            sum /= sign;
        }
        cout<<sum<<endl;
    }
    return 0;
}

