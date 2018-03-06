#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<deque>
#include<iomanip>
#include<sstream>
using namespace std;
int main(){
	int t,cas=0;
	cin>>t;
	while(t--){
		if(cas)
			cout<<endl;
		cas++;
		int n;
		cin>>n;
		getchar();
		string s[25];
		for(int i=0;i<n;i++)
			getline(cin,s[i]);
		string c;
		int mp[1005][25],mpp=0;
		while(getline(cin,c)){
			if(c.empty())
				break;
			stringstream ss;
			ss<<c;
			for(int i=0;i<n;i++)
				ss>>mp[mpp][i];
			mpp++;
		}
		int ans=-1;
		int pr[1005]={0};
		bool isout[25]={0};
		while(1){
			int kp[25]={0};
			for(int i=0;i<mpp;i++){
				if(pr[i]<n)
					kp[mp[i][pr[i]]]++;
			}
			int max=1,min=1;
			for(int i=2;i<=n;i++){
				if(kp[max]==0||kp[max]<kp[i])
					max=i;
				if(kp[min]==0||(kp[i]!=0&&kp[min]>kp[i]))
					min=i;
			}
			if(max==min){
				for(int i=0;i<n;i++){
					if(kp[i+1])
						cout<<s[i]<<endl;
				}
				break;
			}
			else if(kp[max]>mpp){
				ans=max;
				break;
			}
			for(int i=1;i<=n;i++){
				if(kp[i]==kp[min]||kp[i]==0)
					isout[i]=true;
			}
			for(int i=0;i<mpp;i++)
				while(isout[mp[i][pr[i]]])
					pr[i]++;
		}
		if(ans==-1);
		else
			cout<<s[ans-1]<<endl;
	}
	return 0;
}
