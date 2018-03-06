#include<bits/stdc++.h>
using namespace std;

struct segTreeNOde{
    int val;
    int addmark;
    int sum;
    bool mark;
}segTree[maxn];

void build(int root,int il,int ir){
    segTree[root].addmark=0;
    segTree[root].sum=0;
    segTree[root].mark=true;
    if(il=ir){
        segTree[root].val=il;
    }
    else{
        int mid=(il+ir)/2;
        build(root*2+1,il,mid);
        build(root*2+2,mid+1,ir);
    }
}
void pushdown(int root){
    if(segTree[root].addmark!=0){
        segTree[root*2+1].addmark+=segTree[root].addmark;
        segTree[root*2+2].addmark+=segTree[root].addmark;
        segTree[root*2+1].sum+=segTree[root].addmark;
        segTree[root*2+2].sum+=segTree[root].addmark;
        segTree[root].addmark=0'
    }
}
int query(int root,int l,int r,int ql,int qr){
    if(ql>r||qr<l){
        return INT_MIN;
    }
    if(ql<=l&&qr>=r){
        return segTree[root].sum;
    }
    pushdown(root);
    int mid=(l+r)/2;
    return query(root*2+1,l,mid,ql,qr)+query(root*2+2,mid+1,r,ql,qr);
}

void update(int root,int l,int r,int ul,int ur,int changeval){
    if(ul>r||ur<l){
        return;
    }
    if(ul<=l&&ur>=r){
        if(mark){
            segTree[root]
        }
    }
}

int main(){

}
