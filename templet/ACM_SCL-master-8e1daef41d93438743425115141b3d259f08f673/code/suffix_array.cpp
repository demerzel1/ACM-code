/*
数组         值域
rk[0~n-1]   1~n
sa[1~n]    0~n-1
h[2~n] 排名i和排名i-1的后缀的最长公共前缀
h[0~1] 无意义
*/
#define rep(i,a,n) for (i=a;i<n;i++)
int wa[MAXN],wb[MAXN],wv[MAXN],ws[MAXN];
void da(int *r,int *sa,int n,int m=128){
    int i,j,p,*x=wa,*y=wb;
    rep(i,0,m) ws[i]=0;
    rep(i,0,n) ws[x[i]=r[i]]++;
    rep(i,1,m) ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--)sa[--ws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p){
        for(p=0,i=n-j;i<n;i++)y[p++]=i;
        rep(i,0,n) if(sa[i]>=j)y[p++]=sa[i]-j;
        rep(i,0,n)wv[i]=x[y[i]];
        rep(i,0,m)ws[i]=0;
        rep(i,0,n)ws[wv[i]]++;
        rep(i,1,m)ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--)sa[--ws[wv[i]]]=y[i];
        for(swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=
        (y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+j]==y[sa[i]+j])?p-1:p++;
    }
}
int rk[MAXN],h[MAXN];
void geth(int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) rk[sa[i]]=i;
    for(i=0;i<n;h[rk[i++]]=k)
        for(k?k--:0,j=sa[rk[i]-1];r[i+k]==r[j+k];k++);
}