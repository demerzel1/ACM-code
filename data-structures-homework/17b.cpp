#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int t;
int N,T;
int a[100010];

bool hfm(int k){
    long long sum=0;
    queue<long long> q1;
    queue<long long> q2;
//    if((N-1)%(k-1)!=0){
//        for(int i=1;i<=k-1-(N-1)%(k-1);i++)
//            q1.push(0);
//    }
    for(int i=1;i<=N;i++)
        q1.push(a[i]);
    while(1){
            long long c=0;
        for(int i=0;i<k;i++){
            if(q1.size()==0&&q2.size()==0)
                break;
            if(q1.size()==0){
                c+=q2.front();
                q2.pop();
                continue;
            }
            if(q2.size()==0){
                c+=q1.front();
                q1.pop();
                continue;
            }
                long long int x,y;
                x=q1.front();
                y=q2.front();
                if(x<y){
                    c+=x;
                    q1.pop();
                }
                else{
                    c+=y;
                    q2.pop();
                }

        }
        sum+=c;
         if(q1.size()==0&&q2.size()==0)
            break;
        q2.push(c);
    }
    if(sum>T)
        return false;
    else
        return true;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&N,&T);
        for(int i=1;i<=N;i++)
            scanf("%d",&a[i]);
    sort(a+1,a+N+1);
    int l=2,r=N;
        while(l<r){
            int mid=(l+r)>>1;
            if(hfm(mid))
                r=mid;
            else
                l=mid+1;
        }
        printf("%d\n",r);
    }
    return 0;
}
