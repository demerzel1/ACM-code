#include<bits/stdc++.h>
using namespace std;
#define mod(n,m) n>=0?n%m:n%m+m;

int exgcd(int a,int b,int &x,int &y) {
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}

int T;
int n;
int C[20],P[20],L[20];
int start;

int main(){
    cin>>T;
    while(T--){
        memset(C,0,sizeof(C));
        memset(P,0,sizeof(P));
        memset(L,0,sizeof(L));
        start=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>C[i]>>P[i]>>L[i];
            start=max(C[i],start);
        }
        for(int i=start;i<=1000000;i++){
            bool flag=true;
            for(int j=0;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int a=P[j]-P[k];
                    int b=-i;
                    int c=C[k]-C[j];
                    a=mod(a,i);
                    b=mod(b,i);
                    int l=min(L[j],L[k]);
                    int x,y,g;
                    g=exgcd(a,b,x,y);
                    if(c%g!=0)
                        continue;
                   // printf("i=%d x=%d y=%d g=%d a=%d b=%d c=%d l=%d\n",i,x,y,g,a,b,c,l);
                    int down=(int)ceil((-x*c*1.0)/(b*1.0));
                    int up=(int)floor((l*g-x*c)*1.0/(b*1.0));
//                    int down=(int)ceil(((l*g-x*c)*1.0)/(b*1.0));
//                    int up=(int)floor(-x*c*1.0/(b*1.0));
                 //   printf("k1=%d k2=%d\n",down,up);
                    if(down<=up){
                        flag=false;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
            if(flag){
                cout<<i<<"\n";
                break;
            }
        }
    }
    return 0;
}
