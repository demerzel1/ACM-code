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
    int n, m,a[10],ji,laji[10],min;
	while (cin >> n >> m){
            ji=0;
		for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0)
            laji[ji]=a[i];
            ji++;
        }
    if(ji%2==0){
        for(int i=0;i<n;i++)
            if(a[i]!=0)
                m=m*a[i];
        cout<<m<<endl;
        }
    else{
            for(int i=0,min=laji[0];i<ji;i++)
            {
                if(laji[i]<min)
                    min=laji[i];
            }
            for(int i=0;i<n;i++){
                    if(a[i]!=0&&a[i]!=min)
                        m=m*a[i];
            }
             cout<<m<<endl;
		}
	}
    return 0;
}
