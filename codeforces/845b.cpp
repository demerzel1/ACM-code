#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> mx1,mx2,mn1,mn2;
int sum_1,sum_2;

int main(){
    cin>>s;
    for(int i=0;i<3;++i){
        sum_1+=s[i]-'0';
        mx1.emplace_back(9-(s[i]-'0'));
        mn1.emplace_back(s[i]-'0');
    }
    for(int i=3;i<6;++i){
        sum_2+=s[i]-'0';
        mx2.emplace_back(9-(s[i]-'0'));
        mn2.emplace_back(s[i]-'0');
    }
    sort(mx1.begin(),mx1.end(),greater<int>());
    sort(mx2.begin(),mx2.end(),greater<int>());
    sort(mn1.begin(),mn1.end(),greater<int>());
    sort(mn2.begin(),mn2.end(),greater<int>());
    if(sum_1==sum_2){
        cout<<0<<endl;
    }else if(sum_1>sum_2){
        int num=sum_1-sum_2;
        vector<int> v;
        for(int i=0;i<3;i++){
            v.emplace_back(mn1[i]);
            v.emplace_back(mx2[i]);
        }
        sort(v.begin(),v.end(),greater<int>());
        int ans=0,cnt=0;
        for(int i=0;i<6;++i){
            ++ans;
            cnt+=v[i];
            if(cnt>=num)
                break;
        }
        cout<<ans<<endl;
    }else{
        int num=sum_2-sum_1;
        vector<int> v;
        for(int i=0;i<3;i++){
            v.emplace_back(mx1[i]);
            v.emplace_back(mn2[i]);
        }
        sort(v.begin(),v.end(),greater<int>());
        int ans=0,cnt=0;
        for(int i=0;i<6;++i){
            ++ans;
            cnt+=v[i];
            if(cnt>=num)
                break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
