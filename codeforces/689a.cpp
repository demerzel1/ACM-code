#include<bits/stdc++.h>
using namespace std;
int n,b[10];
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>s;
	for (int i=0;i<n;i++)
		b[s[i]-'0']++;
	if ((b[1] || b[2] || b[3]) && (b[7] || b[0] || b[9]) && (((b[1] || b[4] || b[7]) && (b[3] || b[6] || b[9])) || b[0]))
		cout<<"YES";
	else
		cout<<"NO";
    return 0;
}
