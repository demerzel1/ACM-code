#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

#define endl '\n'
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
        memset(data,0,sizeof(data));
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
//查询区间第k大值(由小到大排序后第k个数)
    T query(int L,int R,int l,int r,int dep,int k){
    //    printf("%d %d %d %d %d %d\n",L,R,l,r,dep,k);
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

bool judge(int x,int l,int r,int H){
    if(tree.query(1,tree.n,l,r,0,x)<=H)
        return true;
    return false;
}



int n,m;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        cin>>n>>m;
        tree.init(n);
        for(int i=1;i<=n;i++){
            cin>>tree.data[0][i];
            tree.sorted[i]=tree.data[0][i];
        }
        tree.t_sort();
        tree.build(1,n,0);
        int a,b,c;
        cout<<"Case "<<cas<<":\n";
        while(m--){
            cin>>a>>b>>c;
            a++;
            b++;
            int l=1,r=b-a+1;
            while(r-l>3){
                int mid=(l+r)>>1;
                if(judge(mid,a,b,c))
                    l=mid;
                else
                    r=mid;
            }
            int ans=r;
            for(;ans>=l;ans--){
                if(judge(ans,a,b,c))
                    break;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}