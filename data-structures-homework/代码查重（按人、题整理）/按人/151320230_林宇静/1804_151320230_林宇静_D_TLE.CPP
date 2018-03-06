#include<iostream>
#include<algorithm>
using namespace std;
int n,m,sum;
struct a
{
    int num;
    int index;
};
a p[200010];
int cmp(a x,a y)
{
    return x.num<y.num;
}
int main()
{
    while(scanf("%d%d",&n,&m))
    {
        sum=0;
        int k=0;
        for(int i=0;i<m;i++){
            scanf("%d",&p[k].num);
            p[k].index=0;
            k++;
        }
        for(int i=0;i<n;i++){
            scanf("%d",&p[k].num);
            p[k].index=1;
            k++;
        }
        sort(p,p+k,cmp);
        for(int i=0;i<k;i++){
            if(p[i].index==1){
                int j,t;
                if(i!=k-1){
                for(j=i+1;j<k;j++){
                    if(p[j].index==0)
                        break;
                }
                }
                if(i!=0){
                for(t=i-1;t>=0;t--){
                    if(p[t].index==0)
                        break;
                }
                }
                int Min;
                if(i==0)
                    Min=p[j].num-p[i].num;
                else if(i==k-1)
                    Min=p[i].num-p[t].num;
                else{
                Min=p[j].num-p[i].num;
                if((p[i].num-p[t].num)<Min)
                    Min=p[i].num-p[t].num;
                }
                sum+=Min;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}

