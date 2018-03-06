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
            for(int i=0,min=a[0];i<n;i++)
            {
                if(a[i]<=min)
                    min=a[i];
            }
            for(int i=0;i<n;i++){
                    if(a[i]!=0){
                        if(a[i]!=min&&min<0){
                        min=1;
                        m=m*a[i];
                        }
                    }
            }
             cout<<m<<endl;
		}
	}
    return 0;
}
