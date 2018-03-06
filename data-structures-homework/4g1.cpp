#include<cstdio>
#include<cstring>
int m[200];
int fa(int x){
    if(x!=m[x])
        m[x]=fa(m[x]);
    return m[x];
}
int main(){
    int n,r,i,j,a,b,x,y,f,t;
    int in[200];
    while(scanf("%d%d",&n,&r)!=EOF){
        for(i=0;i<n;i++)
            m[i]=i;
        memset(in,0,sizeof(in));
        for(i=0;i<r;i++){
            scanf("%d%d",&a,&b);
            in[a]++;
            in[b]++;
            a=fa(a);
            b=fa(b);
            m[a]=b;
        }
        f=0;
        for(i=0;i<n;i++)
            if(in[i]%2==1)
                f=1;
        if(r<=1)
            f=1;
        if(f==0)
            for(i=0;i<n;i++)
                if(m[i]!=m[0]&&in[i]!=0)
                    f=1;
        if(f==1)
            printf("Not Possible\n");
        else
            printf("Possible\n");
    }
    return 0;
}
