#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int n, m,a[10],ji,min;
	while (cin >> n >> m){
            ji=0;
		for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0)
            ji++;
        }
    if(ji%2==0){
        for(int i=0;i<n;i++)
            if(a[i]!=0)
                m=m*a[i];
        cout<<m<<endl;
        }
    else{
            min=-11;
            for(int i=0;i<n;i++)
            {
                if(a[i]<0&&a[i]>=min)
                    min=a[i];
            }
            //cout<<min<<endl;
            for(int i=0;i<n;i++){
                    if(a[i]!=0){
                        if(a[i]==min){
                        min=99;
                        }else{
                            m=m*a[i];
                            //cout<<m<<endl;
                        }
                    }
            }
             cout<<m<<endl;
		}
	}
    return 0;
}
