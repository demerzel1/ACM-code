#include<bits/stdc++.h>
using namespace std;

int a[5],b[5],c[5];
//1--b
//2--c
//3--g
int op[4][6]={{},{1,1,2,2,3,3},
            {2,3,1,3,1,2},
            {3,2,3,1,2,1}};
int ans;
map<int,string> mp;
int main(){
    mp[0]="BCG ";
    mp[1]="BGC ";
    mp[2]="CBG ";
    mp[3]="CGB ";
    mp[4]="GBC ";
    mp[5]="GCB ";
    while(cin>>a[1]>>a[3]>>a[2]>>b[1]>>b[3]>>b[2]>>c[1]>>c[3]>>c[2]){
        int n=a[1]+a[2]+a[3]+b[1]+b[2]+b[3]+c[1]+c[2]+c[3];
        ans=INT_MAX;
        int ind=0;
        for(int k=0;k<6;k++){
            int t=0;
            for(int i=1;i<=3;i++){
                if(i==1){
                    t+=a[op[i][k]];
                }
                if(i==2){
                    t+=b[op[i][k]];
                }
                if(i==3){
                    t+=c[op[i][k]];
                }
            }
          //  printf("t=%d\n",t);
            int tans=n-t;
            if(tans<ans){
                ans=tans;
                ind=k;
            }
        }
        cout<<mp[ind]<<ans<<"\n";
    }
    return 0;
}
