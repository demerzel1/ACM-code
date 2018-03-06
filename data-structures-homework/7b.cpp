 #include<iostream>
 #include<cstdio>
 #include<cstring>
 using namespace std;

char qx[27];
char zx[27];

void rec(int ql,int qr,int zl,int zr,int root){
    if(ql>qr)
        return;
  //  root=zl;
    for(root=zl;zx[root]!=qx[ql];++root);
        rec(ql+1,ql+root-zl,zl,root-1,0);
        rec(ql+root-zl+1,qr,root+1,zr,0);
        cout<<zx[root];
}
int main(){
    while(cin>>qx>>zx){
  //     cout<<qx<<endl;
   //    cout<<zx<<endl;
        int N=strlen(qx)-1;
        rec(0,N,0,N,0);
 //    cout<<N;
        cout<<endl;
    }
    return 0;
}
