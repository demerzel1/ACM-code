#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=100010;

//poj 2104

//划分树
//基于快速排序的数据结构 可以离线求区间第k大值

template<class T> struct Tree{
    T data[30][maxn];
    T sorted[maxn];//排序好的数列
    int toleft[30][maxn]; //当前层第i位前有多少数字被划入左子树
    int n;

    void init(int _n){
        n=_n;
    }

    void build(int l,int r,int dep){//建树
        if(l==r)
            return;
        int mid=(l+r)>>1;
        int same=mid-l+1;
        for(int i=l;i<=r;i++)
            if(data[dep][i]<sorted[mid])
                same--;
        int lpos=l,rpos=mid+1;
        for(int i=l;i<=r;i++){
            if(data[dep][i]<sorted[mid]){
                data[dep+1][lpos++]=data[dep][i];
            }else if(data[dep][i]==sorted[mid]&&same>0){
                data[dep+1][lpos++]=data[dep][i];
                same--;
            }else
                data[dep+1][rpos++]=data[dep][i];
            toleft[dep][i]=toleft[dep][l-1]+lpos-l;
        }
        build(l,mid,dep+1);
        build(mid+1,r,dep+1);
    }
//查询区间第k大值
    T query(int L,int R,int l,int r,int dep,int k){
        if(l==r)
            return data[dep][l];
        int mid=(L+R)>>1;
        int cnt=toleft[dep][r]-toleft[dep][l-1];
        if(cnt>=k){
            int newl=L+toleft[dep][l-1]-toleft[dep][L-1];
            int newr=newl+cnt-1;
            return query(L,mid,newl,newr,dep+1,k);
        }
        int newr=r+toleft[dep][R]-toleft[dep][r];
        int newl=newr-(r-l-cnt);
        return query(mid+1,R,newl,newr,dep+1,k-cnt);
    }
    void t_sort(){
        sort(sorted+1,sorted+n+1);
    }
};

Tree<int> tree;

int n,m;
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++){
            scanf("%d",&tree.data[0][i]);
            tree.sorted[i]=tree.data[0][i];
        }
        tree.init(n);
        tree.t_sort();
        tree.build(1,n,0);
        while(m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            int ans=tree.query(1,n,a,b,0,c);
            printf("%d\n",ans);
        }
    }
    return 0;
}